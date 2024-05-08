import os
from pypdf import PdfReader

files = os.listdir(".")
for file in files:
	if not file.endswith("pdf"):
		continue
	reader = PdfReader(file)
	output = "/**"
	afterPageOne = False
	pageName = ""
	for page in reader.pages:
		afterHeader = False
		text = page.extract_text(extraction_mode="layout").split("\n")
		for t in text:
			if len(t) == 0:
				output += "\n"
			if "THINK Reference ©" in t:
				continue
			if pageName != "" and pageName in t:
				continue
			if afterHeader:
				if t.startswith(" "):
					while "\t" in t or "  " in t:
						t = t.replace("\t","").replace("  ","")
					
					if "•" in t:
						output += "\n\t - "+t.replace("•","")
					else:
						output += t+" "
				elif len(t) != 0:
					if t.startswith("Note:"):
						output += t.replace("Note:","\\note")
					else:
						output += "\n\t\t"+t+"\n"
			else:
				if not t.startswith(" "):
					afterHeader = True
					if not afterPageOne:
						pageName = t.split("Page")[0].split("  ")[0]
						output += "\n\t\\name "+pageName+"\n\n\t"
						afterPageOne = True
				
	output += "\n*/\n"

	while "  " in output:
		output = output.replace("  "," ")

	f = open("./translated/"+pageName.replace(" ","_").replace("/","").lower()+".c","w")
	f.write(output)
	f.close()
				
