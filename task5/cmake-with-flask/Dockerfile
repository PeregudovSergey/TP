FROM gcc:latest as build

RUN apt-get update && apt-get -y install cmake

COPY CMakeLists.txt ./app/CMakeLists.txt
COPY B ./app/B
COPY C ./app/C
COPY app.py ./app/app.py
RUN mkdir ./app/build && cd ./app/build && cmake .. && make
#RUN ././app/bin/C
