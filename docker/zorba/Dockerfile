FROM ubuntu:12.04.5

MAINTAINER 28msec <hello@28.io>

RUN apt-get update -y
RUN apt-get install python-software-properties -y
RUN add-apt-repository ppa:fcavalieri/zorba -y
RUN apt-get update -y
RUN apt-get install zorba.* -y

ENTRYPOINT ["zorba"]
CMD ["-h"]

VOLUME /queries
WORKDIR /queries
