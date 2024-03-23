from fpdf import FPDF

def main():

    name = input("Name: ")

    pdf = FPDF()
    pdf.add_page()
    pdf.image("shirtificate.png", (210 - 180) / 2, 80, w=180)
    pdf.set_font('helvetica', size=26, style='B')
    pdf.set_text_color(255, 255, 255)
    pdf.cell(200, 260, text=f"{name} took CS50", align='C')
    pdf.output("hello_world.pdf")

if __name__ == "__main__":
    main()
