1. tạo file calculator.proto
2. biên dịch file này thành bằng câu lệnh
    
    - `protoc -I=. --grpc_out=. --plugin=protoc-gen-grpc=/usr/bin/grpc_cpp_plugin caculator.proto `

    - `protoc -I=./ --cpp_out=./ ./caculator.proto`
3. tạo file server.cc và client.cc
    
    - `sau đó chạy lệnh makefile`
4. Chương trình đã biên dịch thành công bây giờ chạy file

    `./server` -> `./client`     
    