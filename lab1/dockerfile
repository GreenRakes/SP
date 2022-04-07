FROM debian
COPY lab1.sh .
COPY . /vdovina
RUN chmod ugo+x lab1.sh && apt-get update && apt-get -y install isomd5sum
CMD ./lab1.sh 
