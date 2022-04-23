FROM gcc:latest as build

RUN apt-get update && apt-get -y install cmake

COPY ./ /opt/techprog/
RUN mkdir /opt/techprog/build && cd /opt/techprog/build && cmake .. && make
#RUN ././app/bin/C
