FROM ubuntu

MAINTAINER martinicr

RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y libgtk-3-dev

RUN apt-get install -y git-core

# Replace 1000 with your user / group id
RUN export uid=1000 gid=1000 && \
    mkdir -p /home/developer && \
    mkdir -p /etc/sudoers.d && \
    echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
    echo "developer:x:${uid}:" >> /etc/group && \
    echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && \
    chmod 0440 /etc/sudoers.d/developer && \
    chown ${uid}:${gid} -R /home/developer

USER developer
ENV HOME /home/developer


RUN git clone https://github.com/sistemas-operativos-avanzados/threadville.git /home/developer/threadville && \
    cd /home/developer/threadville && \
    git checkout integracion && \
    make

WORKDIR /home/developer/threadville

ENTRYPOINT ["target/threadville"]