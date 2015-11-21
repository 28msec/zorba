FROM ubuntu:12.04.5

MAINTAINER 28msec <hello@28.io>


RUN apt-get update -y
RUN apt-get install python-software-properties -y
#RUN add-apt-repository ppa:fcavalieri/zorba -y
#RUN add-apt-repository -y ppa:fcavalieri/sausalito
RUN apt-get update -y

#Core
RUN apt-get install -y build-essential cmake libxml2-dev libicu-dev  libxerces-c-dev libcurl4-openssl-dev uuid-dev libxslt-dev

#Parser
RUN apt-get install -y m4 wget
RUN wget http://launchpadlibrarian.net/160037457/bison_3.0.2.dfsg-2_amd64.deb
RUN wget http://launchpadlibrarian.net/160037458/libbison-dev_3.0.2.dfsg-2_amd64.deb
RUN dpkg -i libbison-dev_3.0.2.dfsg-2_amd64.deb bison_3.0.2.dfsg-2_amd64.deb

#Lexer
RUN wget https://launchpad.net/ubuntu/+source/flex/2.5.39-8/+build/6118519/+files/libfl-dev_2.5.39-8_amd64.deb
RUN wget https://launchpad.net/ubuntu/+source/flex/2.5.39-8/+build/6118519/+files/flex_2.5.39-8_amd64.deb
RUN dpkg -i libfl-dev_2.5.39-8_amd64.deb flex_2.5.39-8_amd64.deb

#Documentation
RUN apt-get install -y doxygen texlive

#Test Driver
RUN apt-get install -y libboost-filesystem-dev

#External modules extra repositories
RUN apt-get install -y python-software-properties
RUN add-apt-repository --yes ppa:fcavalieri/zorba
RUN wget -O/etc/apt/sources.list.d/couchbase.list http://packages.couchbase.com/ubuntu/couchbase-ubuntu1204.list
RUN wget  http://packages.couchbase.com/ubuntu/couchbase.key
RUN apt-key add couchbase.key
RUN apt-get update

#External modules dependencies
RUN apt-get install -y libarchive-dev
RUN apt-get install -y graphviz-dev
RUN apt-get install -y openjdk-7-jdk
RUN wget http://download.oracle.com/otn-pub/otn_software/nosql-database/kv-c-driver_3.3.5-0_amd64.deb
RUN dpkg -i kv-c-driver_3.3.5-0_amd64.deb
RUN apt-get install -y libfontbox-java libjempbox-java libpdfbox-java libcommons-logging-java
RUN apt-get install -y libtidy-dev
RUN apt-get install -y libc-client2007e-dev=8:2007e-1~dfsg-3.2ubuntu1zorba2
RUN apt-get install -y libsqlite3-dev
RUN apt-get install -y libcouchbase-dev
RUN apt-get install -y libmagick++-dev
RUN apt-get install -y libgeos++-dev
RUN apt-get install -y xmlbeans
RUN apt-get install -y libfop-java libcommons-logging-java
RUN locale-gen de_DE && locale-gen de_DE.UTF-8 && locale-gen fr_FR && locale-gen fr_FR.UTF-8 && update-locale

#Zorba Server
RUN apt-get install -y nginx spawn-fcgi libfcgi-dev

VOLUME /zorba

ENTRYPOINT ["./zorba/docker-dev/entrypoint.sh"]
