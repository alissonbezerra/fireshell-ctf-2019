FROM ubuntu:17.10

RUN apt-get update -y && apt-get install xinetd -y

RUN mkdir -p /app/casino

ADD casino.sh /app/casino
ADD casino /app/casino
ADD flag.txt /app/casino
ADD init.sh /bin
ADD casino.xinetd /etc/xinetd.d/casino

RUN groupadd -r casino && useradd -r -g casino casino && \
    chown -R root:casino /app/casino && \
    chmod 750 /app/casino/casino.sh && \
    chmod 750 /app/casino/casino && \
    chmod 440 /app/casino/flag.txt && \
    chmod 700 /bin/init.sh

RUN service xinetd restart

ENTRYPOINT [ "/bin/init.sh" ]

EXPOSE 2001
