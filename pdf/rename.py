import os
from pypdf import PdfReader
import re 

files = os.listdir(".")
for file in files:
	if not file.endswith("pdf"):
		continue
	reader = PdfReader(file)
	page = reader.pages[0]
	fullName = page.extract_text().split("\n")[0].split("Page")[0]
	fileName = fullName.lower().replace(" ","_").replace("-","_").replace("/","\\").replace("\'","")
	fileName = re.sub("[^A-Za-z0-9]","_",fileName)
	if fileName.endswith("_"):
		fileName = fileName[:len(fileName)-1]
	os.rename(file, "".join(fileName)+".pdf")

	f = open(fileName+".md", "w")
	f.write("""
/**
	\\page """+fileName+""" """+fullName+"""

	\\htmlonly
	<script type="module" src="https://cdnjs.cloudflare.com/ajax/libs/pdf.js/4.2.67/pdf.min.mjs"></script>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/pdf.js/4.2.67/pdf_viewer.min.css">

	<script type="module">
		// If absolute URL from the remote server is provided, configure the CORS
		// header on that server.
		var url = '../pdf/"""+fileName+""".pdf';

		// Loaded via <script> tag, create shortcut to access PDF.js exports.
		var { pdfjsLib } = globalThis;

		// The workerSrc property shall be specified.
		pdfjsLib.GlobalWorkerOptions.workerSrc = '//cdnjs.cloudflare.com/ajax/libs/pdf.js/4.2.67/pdf.worker.min.mjs';

		var pdfDoc = null,
			pageNum = 1,
			pageRendering = false,
			pageNumPending = null,
			scale = 0.8,
			canvas = document.getElementById('the-canvas'),
			ctx = canvas.getContext('2d');

		/**
		* Get page info from document, resize canvas accordingly, and render page.
		* @param num Page number.
		*/
		function renderPage(num) {
			pageRendering = true;
			// Using promise to fetch the page
			pdfDoc.getPage(num).then(function(page) {
			var viewport = page.getViewport({scale: scale});
			canvas.height = viewport.height;
			canvas.width = viewport.width;

			// Render PDF page into canvas context
			var renderContext = {
				canvasContext: ctx,
				viewport: viewport
			};
			var renderTask = page.render(renderContext);

			// Wait for rendering to finish
			renderTask.promise.then(function() {
				pageRendering = false;
				if (pageNumPending !== null) {
				// New page rendering is pending
				renderPage(pageNumPending);
				pageNumPending = null;
				}
			});
			});

			// Update page counters
			document.getElementById('page_num').textContent = num;
		}

		/**
		* If another page rendering in progress, waits until the rendering is
		* finised. Otherwise, executes rendering immediately.
		*/
		function queueRenderPage(num) {
			if (pageRendering) {
			pageNumPending = num;
			} else {
			renderPage(num);
			}
		}

		/**
		* Displays previous page.
		*/
		function onPrevPage() {
			if (pageNum <= 1) {
			return;
			}
			pageNum--;
			queueRenderPage(pageNum);
		}
		document.getElementById('prev').addEventListener('click', onPrevPage);

		/**
		* Displays next page.
		*/
		function onNextPage() {
			if (pageNum >= pdfDoc.numPages) {
			return;
			}
			pageNum++;
			queueRenderPage(pageNum);
		}
		document.getElementById('next').addEventListener('click', onNextPage);

		/**
		* Asynchronously downloads PDF.
		*/
		pdfjsLib.getDocument(url).promise.then(function(pdfDoc_) {
			pdfDoc = pdfDoc_;
			document.getElementById('page_count').textContent = pdfDoc.numPages;

			// Initial/first page rendering
			renderPage(pageNum);
		});
	</script>
	<div>
	<button id="prev">Previous</button>
	<button id="next">Next</button>
	&nbsp; &nbsp;
	<span>Page: <span id="page_num"></span> / <span id="page_count"></span></span>
	</div>

	<canvas id="the-canvas"></canvas>
	\\endhtmlonly		 
*/

""")
