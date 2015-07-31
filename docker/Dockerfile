FROM ubuntu:14.04.5

MAINTAINER 28msec <hello@28.io>

RUN sudo add-apt-repository ppa:fcavalieri/zorba
RUN sudo apt-get update
RUN sudo apt-get install zorba.*

ENTRYPOINT ["zorba"]
CMD ["-h"]

#RUN mkdir /queries
VOLUME /queries
WORKDIR /queries
