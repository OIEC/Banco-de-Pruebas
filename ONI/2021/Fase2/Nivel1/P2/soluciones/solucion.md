**Solución:**

Para resolver este problema lo primero que hay que hacer es encontrar cuándo un día es frío, caluroso, y estable. 
Para esto, solo necesitamos saber la temperatura mínima y la máxima de un día, porque así podemos determinar que, si la diferencia entre ambos valores es menor o igual a 5, entonces es un día _estable_; 
además es un día _frío_ si la mínima es menor a 7, o es un día _caluroso_ si la máxima es mayor a 28.

Ya teniendo estos datos, podemos empezar a leer la entrada línea por línea considerando que cada semana consta de 7 días. Luego, imprimimos los datos de cada semana en el orden requerido. 
