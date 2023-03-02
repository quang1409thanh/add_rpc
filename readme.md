# RPC:

## 1.Giới thiệu
### 1.1 RPC là gì:
    - RPC (Remote Procedure Call) là một giao thức cho phép các ứng dụng được chạy trên các máy tính khác nhau trong mạng kết nối với nhau và giao tiếp với nhau như thể chúng đang chạy trên cùng một máy tính. Giao thức RPC cho phép các ứng dụng gửi các yêu cầu và nhận các phản hồi từ các ứng dụng khác trong mạng.

    - Các ứng dụng sử dụng RPC để gọi các thủ tục (procedures) từ các ứng dụng khác. Mỗi thủ tục là một tập hợp các câu lệnh được thực thi khi được gọi. Khi một ứng dụng gọi một thủ tục thông qua RPC, nó sẽ gửi một thông điệp yêu cầu đến ứng dụng đang chạy trên một máy tính khác. Ứng dụng nhận yêu cầu này, thực thi thủ tục tương ứng và trả về kết quả cho ứng dụng ban đầu.

    - Các ứng dụng sử dụng RPC để gọi các thủ tục (procedures) từ các ứng dụng khác. Mỗi thủ tục là một tập hợp các câu lệnh được thực thi khi được gọi. Khi một ứng dụng gọi một thủ tục thông qua RPC, nó sẽ gửi một thông điệp yêu cầu đến ứng dụng đang chạy trên một máy tính khác. Ứng dụng nhận yêu cầu này, thực thi thủ tục tương ứng và trả về kết quả cho ứng dụng ban đầu.
### 1.2 Các hệ thống RPC
    -gRPC: được phát triển bởi Google, gRPC sử dụng giao thức HTTP/2 và hỗ trợ nhiều ngôn ngữ lập trình khác nhau.

    -Apache Thrift: được phát triển bởi Apache, Thrift là một nền tảng RPC đa nền tảng, hỗ trợ nhiều ngôn ngữ lập trình và các giao thức truyền thông khác nhau.

    -Apache Avro: cũng được phát triển bởi Apache, Avro là một hệ thống RPC với khả năng tự động sinh mã, hỗ trợ nhiều ngôn ngữ lập trình và cho phép giao tiếp qua nhiều giao thức truyền thông.

    -Microsoft RPC: Microsoft RPC là một hệ thống RPC phát triển bởi Microsoft, được sử dụng trong các ứng dụng Windows.

    -XML-RPC: đây là một hệ thống RPC đơn giản và dễ sử dụng, được sử dụng để kết nối các ứng dụng web với nhau.

    -JSON-RPC: là một hệ thống RPC sử dụng định dạng JSON để truyền tải dữ liệu và được sử dụng trong các ứng dụng web.

    -MessagePack-RPC: là một hệ thống RPC sử dụng định dạng MessagePack để truyền tải dữ liệu, nhanh hơn và tiết kiệm băng thông hơn so với JSON-RPC.
## 2.Cài Đặt 
### 2.1 Các gói cần có

1. Cài đặt gói build-essential:
    * `sudo apt-get install build-essential`
2. Cài đặt gói cmake:
    * `sudo apt-get install cmake`
3. Cài đặt gói git:
    * `sudo apt-get install git`
4. Cài đặt gói protobuf-compiler:
    * `sudo apt-get install protobuf-compiler`
5. Cài đặt thư viện GRPC:
    * `sudo apt-get install libgrpc-dev`
### 2.1 Cài đặt 
    Tùy thuộc vào ngôn ngữ của mình mà cài đặt 
    Sau khi cài đặt 5 bước trên thì mình làm tiếp
    
* C++: `sudo apt-get install libgrpc++-dev`
* Java: `sudo apt-get install libgrpc-java`

```Nếu là ngôn ngữ Python thì không cần thiết phải cài đặt 5 gói này. Tuy nhiên nếu ứng dụng cần thêm thêm các gói này thì nên cài đặt```
* Python `pip install grpcio grpcio-tools
`


## 3.Check
Mình sẽ kiểm tra cài đặt grpc++ trong c++
Giả sử  mình viết 1 hàm để in ra thông báo cài đặt GRPC thành công
    
    #include <iostream>
    #include <grpc++/grpc++.h>

    using grpc::Channel;
    using grpc::ClientContext;
    using grpc::Status;

    int main(int argc, char** argv) {
        std::cout<<" bạn đã cài đặt thành công grpc++";
        return 0;
    }
Sau đó biên dịch
    
    g++ -std=c++11 -I/usr/include/grpc -pthread test_grpc.cpp     -L/usr/lib/x86_64-linux-gnu -lgrpc++ -lgrpc -lprotobuf -pthread -ldl
Các tùy chọn trong câu lệnh biên dịch là 
Các tùy chọn trong câu lệnh:

    g++: trình biên dịch C++ được sử dụng để biên dịch chương trình.
    -std=c++11: tùy chọn để sử dụng tiêu chuẩn C++11 cho chương trình.
    -I/usr/include/grpc: thư mục chứa các tệp đầu vào (header files) cho gRPC library.
    -pthread: tùy chọn để sử dụng pthread library cho threading (đa luồng).
    test_grpc.cpp: tên tệp nguồn C++ của chương trình.
    -L/usr/lib/x86_64-linux-gnu: thư mục chứa các thư viện liên kết (link libraries).
    -lgrpc++ -lgrpc -lprotobuf: các thư viện liên kết để sử dụng gRPC library và protobuf library.
    -ldl: thư viện liên kết để sử dụng dynamic linking.
Nếu biên dịch thành công thì mình chạy chương trình 
    
    ./a.out

Nếu chương trình in ra câu lệnh:`  bạn đã cài đặt thành công grpc++` 
Đến đây mình đã hoàn thành việc thêm thư viện grpc
