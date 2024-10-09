FROM ubuntu:22.04

RUN mkdir -p /home
WORKDIR /home

RUN mkdir -p /home/include
RUN mkdir -p /home/src
RUN mkdir -p /home/test

COPY include/* /home/include
COPY src/* /home/src
COPY test/* /home/test
COPY CMakeLists.txt /home

RUN apt-get update && apt-get install build-essential cmake -y

RUN cmake . && cmake --build .