#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "calculator.grpc.pb.h"

using calculator::CalculationRequest;
using calculator::CalculationResponse;
using calculator::Calculator;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class CalculatorServer final : public Calculator::Service
{
    Status Add(ServerContext *context, const CalculationRequest *request, CalculationResponse *response) override
    {
        response->set_result(request->a() + request->b());
        return Status::OK;
    }
    Status Sub(ServerContext *context, const CalculationRequest *request, CalculationResponse *response) override
    {
        response->set_result(request->a() - request->b());
        return Status::OK;
    }
    Status Mul(ServerContext *context, const CalculationRequest *request, CalculationResponse *response) override
    {
        response->set_result(request->a() * request->b());
        return Status::OK;
    }
    Status Div(ServerContext *context, const CalculationRequest *request, CalculationResponse *response) override
    {
        response->set_result(request->a() / request->b());
        return Status::OK;
    }
};

void RunServer()
{
    std::string server_address("0.0.0.0:50051");
    CalculatorServer service;
    grpc::ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to *serving* the "Greeter" service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}
int main(int argc, char **argv)
{
    RunServer();

    return 0;
}