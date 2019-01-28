FROM ubuntu:17.10

RUN dpkg --add-architecture i386 && apt-get update -y && apt-get install xinetd libc6:i386 libncurses5:i386 libstdc++6:i386 -y

RUN mkdir -p /app/leakless

ADD leakless.sh /app/leakless
ADD leakless /app/leakless
ADD flag.txt /app/leakless
ADD init.sh /bin
ADD leakless.xinetd /etc/xinetd.d/leakless

RUN groupadd -r leakless && useradd -r -g leakless leakless && \
    chown -R root:leakless /app/leakless && \
    chmod 750 /app/leakless/leakless.sh && \
    chmod 750 /app/leakless/leakless && \
    chmod 440 /app/leakless/flag.txt && \
    chmod 700 /bin/init.sh

RUN service xinetd restart

ENTRYPOINT [ "/bin/init.sh" ]

EXPOSE 2002
