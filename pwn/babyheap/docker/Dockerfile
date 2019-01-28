FROM ubuntu:17.10

RUN apt-get update -y && apt-get install xinetd -y

RUN mkdir -p /app/babyheap

ADD babyheap.sh /app/babyheap
ADD babyheap /app/babyheap
ADD flag.txt /app/babyheap
ADD init.sh /bin
ADD babyheap.xinetd /etc/xinetd.d/babyheap

RUN groupadd -r babyheap && useradd -r -g babyheap babyheap && \
    chown -R root:babyheap /app/babyheap && \
    chmod 750 /app/babyheap/babyheap.sh && \
    chmod 750 /app/babyheap/babyheap && \
    chmod 440 /app/babyheap/flag.txt && \
    chmod 700 /bin/init.sh

RUN service xinetd restart

ENTRYPOINT [ "/bin/init.sh" ]

EXPOSE 2000
