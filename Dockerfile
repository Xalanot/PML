from ubuntu:latest

RUN apt-get update

RUN apt-get install -y \
    apt-transport-https \ 
    ca-certificates \ 
    git \
    gnupg \
    software-properties-common \
    wget

RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | apt-key add -
RUN apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main'

RUN apt-get update

RUN apt-get install -y \
    cmake \
    gcc-10

