FROM ubuntu:vivid

MAINTAINER Federico Cavalieri <f@28.io>

RUN apt-get update -y
RUN apt-get install software-properties-common -y
RUN add-apt-repository ppa:fcavalieri/zorba -y
RUN apt-get update -y

#Prerequisites
# - Utils
RUN apt-get install git wget -y

# - Build
RUN apt-get install build-essential cmake -y

# - Zorba Core
RUN apt-get install libxml2-dev libicu-dev uuid-dev libxerces-c-dev libxslt-dev libcurl4-openssl-dev openjdk-8-jdk -y

# - Documentation
RUN apt-get install doxygen texlive -y

# - Lexer and Parser
RUN apt-get install m4 bison libbison-dev flex libfl-dev -y

# - MT Testdriver:
RUN apt-get install libboost-filesystem-dev libboost-system-dev -y

# - External Modules:
RUN apt-get install libfop-java graphviz-dev libtidy-dev libarchive-dev libmagick++-dev libgeos++-dev libsqlite3-dev libpdfbox-java libfontbox-java libjempbox-java xmlbeans -y

#- NoSQL External Module: 
RUN wget http://download.oracle.com/otn-pub/otn_software/nosql-database/kv-c-driver_3.3.5-0_amd64.deb 
RUN dpkg -i kv-c-driver_3.3.5-0_amd64.deb
RUN rm kv-c-driver_3.3.5-0_amd64.deb 

# Couchbase External Module: 
RUN wget -O/etc/apt/sources.list.d/couchbase.list http://packages.couchbase.com/ubuntu/couchbase-ubuntu1404.list
RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-keys A3FAA648D9223EDA
RUN apt-get update -y
RUN apt-get install libcouchbase-dev -y

# - Email External Module
RUN apt-get install libc-client2007e-dev libssl-dev libkrb5-dev libpam0g-dev -y

# - Fix Locales
RUN locale-gen de_DE && locale-gen de_DE.UTF-8 && locale-gen fr_FR && locale-gen fr_FR.UTF-8 && update-locale

#SSH
RUN apt-get install openssh-server -y && \
    mkdir -p /var/run/sshd && \
    /bin/sh -c 'echo root:zorba | chpasswd'
RUN sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/' /etc/ssh/sshd_config

#Expose
VOLUME /zorba
EXPOSE 22

#Entrypoint
COPY docker-entrypoint.sh /docker-entrypoint.sh
ENTRYPOINT ["/docker-entrypoint.sh"]
