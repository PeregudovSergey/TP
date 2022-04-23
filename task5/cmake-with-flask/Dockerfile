FROM ubuntu

RUN apt-get update && apt-get install -y cmake build-essential
COPY ./ /opt/techprog/
RUN mkdir /opt/techprog/build && cd /opt/techprog/build && cmake .. && make

WORKDIR /opt/techprog/
RUN groupadd -r tp2022user && useradd -r -g tp2022user tp2022user
USER tp2022user

#RUN cmake . && make
#RUN ././app/bin/C

