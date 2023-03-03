all:
	g++ -std=c++11 -I/usr/include -pthread client.cc calculator.grpc.pb.cc calculator.pb.cc     -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc` -o client
	g++ -std=c++11 -I/usr/include -pthread server.cc calculator.grpc.pb.cc calculator.pb.cc     -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc` -o server