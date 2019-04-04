
CFLAGS := -Wall -o3

all: dc-makeip dc-scramble

dc-makeip: makeip.c ip_tmpl.c
	$(CC) $(CFLAGS) -o $@ $+

dc-scramble: scramble.c
	$(CC) $(CFLAGS) -o $@ $+

ip_tmpl.c: bin2c
	./bin2c IP.TMPL $@ default_ip_tmpl 

bin2c: bin2c.c
	$(CC) $(CFLAGS) -o $@ $+

.PHONY: clean
clean:
	rm -f bin2c dc-makeip dc-scramble ip_tmpl.c *.o
