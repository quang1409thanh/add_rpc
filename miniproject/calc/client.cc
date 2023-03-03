#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "calculator.grpc.pb.h"

using calculator::CalculationRequest;
using calculator::CalculationResponse;
using calculator::Calculator;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class CalculatorClient
{
public:
    CalculatorClient(std::shared_ptr<Channel> channel) : stub_(Calculator::NewStub(channel)) {}
    double Add(double a, double b)
    {
        CalculationRequest request;
        request.set_a(a);
        request.set_b(b);

        CalculationResponse reply;
        ClientContext context;

        Status status = stub_->Add(&context, request, &reply);
        if (status.ok())
        {
            std::cout << "Kết quả phép cộng là: ";
            return reply.result();
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            std::cout << "RPC failed";
            return 0;
        }
    }
    double Sub(double a, double b)
    {
        CalculationRequest request;
        request.set_a(a);
        request.set_b(b);

        CalculationResponse reply;
        ClientContext context;

        Status status = stub_->Sub(&context, request, &reply);
        if (status.ok())
        {
            std::cout << "Kết quả phép trừ là: ";
            return reply.result();
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            std::cout << "RPC failed";
            return 0;
        }
    }
    double Mul(double a, double b)
    {
        CalculationRequest request;
        request.set_a(a);
        request.set_b(b);

        CalculationResponse reply;
        ClientContext context;

        Status status = stub_->Mul(&context, request, &reply);
        if (status.ok())
        {
            std::cout << "Kết quả phép nhân là: ";
            return reply.result();
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            std::cout << "RPC failed";
            return 0;
        }
    }
    double Div(double a, double b)
    {
        CalculationRequest request;
        request.set_a(a);
        request.set_b(b);

        CalculationResponse reply;
        ClientContext context;

        Status status = stub_->Div(&context, request, &reply);
        if (status.ok())
        {
            std::cout << "Kết quả phép chia là: ";
            return reply.result();
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            std::cout << "RPC failed";
            return 0;
        }
    }

private:
    std::unique_ptr<Calculator::Stub> stub_;
};
int main(int argc, char **argv)
{
    // Create a channel to the server
    std::string server_address("localhost:50051");
    CalculatorClient greeter(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));

    // Call Add RPC
    double a = 99;
    double b = 10;

    std::cout << "! Server replied:\n " << greeter.Add(a, b) << "\n"
              << greeter.Sub(a, b) << "\n"
              << greeter.Mul(a, b) << "\n"
              << greeter.Div(a, b) << std::endl;

    return 0;
}
