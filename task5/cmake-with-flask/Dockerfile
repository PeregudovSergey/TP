FROM ubuntu

RUN apt-get update && apt-get install -y cmake g++
RUN apt-get install -y python3-pip
RUN pip install flask
COPY ./ /opt/techprog/
RUN mkdir /opt/techprog/build && cd /opt/techprog/build && cmake .. && make
WORKDIR /opt/techprog/
RUN groupadd -r tp2022user && useradd -r -g tp2022user tp2022user
USER tp2022user

EXPOSE 8898
CMD ["python3", "/opt/techprog/app.py", "--port", "8898", "--host", "0.0.0.0"]

#RUN cmake . && make
#RUN ././app/bin/C

