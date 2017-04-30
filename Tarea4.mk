Resultados_hw4.pdf: Resultados_hw4.tex Plots_Temperatura.py
	pdflatex $<
	python Plots_Temperatura.py
Plots_Temperatura.py: a.out
	./a.out
a.out: DifusionTemperatura.c
	cc DifusionTemperatura.c -lm
