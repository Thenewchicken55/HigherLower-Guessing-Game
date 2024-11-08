.PHONY: run
run: build
	./main

build: main.cpp
	g++ -o main main.cpp

.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -f main
	@echo "Done."

run-python:
	python3 main.py