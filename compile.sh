g++ -c src/Paddle.cpp -o build/Paddle.o
g++ -c src/Ball.cpp -o build/Ball.o
g++ -c src/Brick.cpp -o build/Brick.o
g++ -c src/main.cpp -o build/main.o
g++ build/Paddle.o build/Brick.o build/Ball.o build/main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
./main
