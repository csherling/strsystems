strtest: str.c
	gcc str.c -o str

clean:
	rm str

run: strtest
	./str