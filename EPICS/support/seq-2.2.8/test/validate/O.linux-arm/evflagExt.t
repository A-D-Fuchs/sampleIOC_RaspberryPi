$ENV{HARNESS_ACTIVE} = 1;
$ENV{TOP} = '/home/epics/EPICS/support/seq-2.2.8';
$ENV{PATH} = '/home/epics/EPICS/support/seq-2.2.8/bin/linux-arm:/home/epics/EPICS/epics-base/bin/linux-arm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/games:/usr/games';
$ENV{EPICS_CA_SERVER_PORT} = 10000 + $$ % 30000;
#only for debugging:
#print STDERR "port=$ENV{EPICS_CA_SERVER_PORT}\n";
system "./evflagExt -S -t";
