FROM gcc:4.9

RUN apt-get update
RUN apt-get install -y python-dev