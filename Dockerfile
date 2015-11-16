FROM ubuntu:12.04.5

MAINTAINER 28msec <hello@28.io>

RUN apt-get update -qq
RUN apt-get install -y uuid-dev libxerces-c-dev graphviz libboost-filesystem-dev libgeos++-dev imagemagick libmagick++-dev libmagickwand-dev libfop-java libpdfbox-java libtidy-dev libjempbox-java libfontbox-java libarchive-dev libmysqlclient-dev openjdk-6-jdk libaccess-bridge-java-jni libxslt-dev libcurl4-openssl-dev libxerces-c-dev doxygen libedit-dev libkvutils-dev
RUN apt-get install -y wget m4 cmake

RUN locale-gen de_DE && locale-gen de_DE.UTF-8 && locale-gen fr_FR && locale-gen fr_FR.UTF-8 && update-locale

RUN wget http://launchpadlibrarian.net/160037457/bison_3.0.2.dfsg-2_amd64.deb
RUN wget http://launchpadlibrarian.net/160037458/libbison-dev_3.0.2.dfsg-2_amd64.deb
RUN dpkg -i libbison-dev_3.0.2.dfsg-2_amd64.deb bison_3.0.2.dfsg-2_amd64.deb
RUN wget https://launchpad.net/ubuntu/+source/flex/2.5.39-8/+build/6118519/+files/libfl-dev_2.5.39-8_amd64.deb
RUN wget https://launchpad.net/ubuntu/+source/flex/2.5.39-8/+build/6118519/+files/flex_2.5.39-8_amd64.deb
RUN dpkg -i libfl-dev_2.5.39-8_amd64.deb flex_2.5.39-8_amd64.deb

VOLUME /zorba

ENTRYPOINT ["./zorba/docker_entrypoint.sh"]
