from fpdf import FPDF

pdf = FPDF()
pdf.add_page()
pdf.set_font('helvetica', size=12)
pdf.image("shirtificate.png", w=100)
pdf.cell(text="hello world")
pdf.output("hello_world.pdf")
