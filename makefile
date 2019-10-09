ev_ftp_server:ev_ftp_server.cpp XThread.cpp XThreadPool.cpp\
 XFtpServerCMD.cpp XFtpTask.cpp XFtpFactory.cpp XFtpUSER.cpp\
 XFtpLIST.cpp XFtpPORT.cpp XFtpRETR.cpp XFtpSTOR.cpp
	g++ $^ -o $@ -levent -pthread -g
	gdb ./$@
clean:
	rm -rf ev_ftp_server
	rm -rf *.o

