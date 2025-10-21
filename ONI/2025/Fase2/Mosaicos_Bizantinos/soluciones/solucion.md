Como el orden no importa y los colores se pueden repetir, basta con contar cuántas teselas de cada color hay en ambas listas.

Si un color aparece más veces en la lista inicial → sobran → hay que descartar o reemplazar.

Si un color aparece más veces en la lista final → faltan → hay que añadir o reemplazar.

En resumen, para cada color $c$:

diferencia[c] = |freq_inicial[c] - freq_final[c]|.

Cómo calcular el número mínimo de cambios:

Sumemos todos los excesos (colores con más teselas en la lista inicial).

Sumemos todas las faltas (colores con menos teselas en la lista inicial).

Los reemplazos pueden emparejar un exceso con una falta directamente.

Por lo tanto: cambios = max(excesos, faltas).