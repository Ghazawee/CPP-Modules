#include "Serializer.hpp"
#include "Data.hpp"

int main(){
    Data* data = new Data;
    data->id = 1;
    data->name = "Shaolin";
    data->worth = "Rich in wisdom";
    data->value = 1111;

    std::cout << "Original Data: " <<  data << std::endl;
    std::cout << "ID: " << data->id << std::endl;
    std::cout << "Name: " << data->name <<std::endl; 
    std::cout << "Worth: " << data->worth << std::endl; 
    std::cout << "Value: " << data->value << std::endl;

    uintptr_t serialDataKiller = Serializer::serialize(data);
    std::cout << "Serialized Data: " << serialDataKiller << std::endl
                << " (as uintptr_t)" << std::endl;
    Data* deserializedData = Serializer::deserialize(serialDataKiller);

    if (data == deserializedData){
        std::cout << "Deserialization successful!, they match" << std::endl;
        std::cout << "Deserialized Data: " << deserializedData<< std::endl;
        std::cout << "ID: " << deserializedData->id << std::endl;
        std::cout << "Name: " << deserializedData->name << std::endl; 
        std::cout << "Worth: " << deserializedData->worth << std::endl; 
        std::cout << "Value: " << deserializedData->value << std::endl;
    }
    else{
        std::cout << "Deserialization failed, they do not match" << std::endl;
    }

    delete data;
    return 0;
}