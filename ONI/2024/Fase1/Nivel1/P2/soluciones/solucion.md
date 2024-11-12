Para la primera subtarea tenemos 3 casos posibles para que la palabra $s$ cumpla. La palabra cumple si alguno de los grupos $\{s[0], s[1] y s[2]\}$, $\{s[1], s[2] y s[3]\}$, $\{s[2], s[3] y s[4]\}$ constan de todas vocales.

Para la segunda subtarea podemos generalizar lo anterior e iterar sobre $i = 0$ hasta $N-3$, verificando si alguno de los grupos $\{s[i], s[i+1] y s[i+2]\}$ consta de todas vocales.
