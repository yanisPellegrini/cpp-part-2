#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;
    data.id = 771231;
    data.name = "John Doe";

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);


    std::cout << "Adresse originale : " << &data << std::endl;
    std::cout << "Valeur serialisee : " << raw << std::endl;
    std::cout << "Adresse retrouvee : " << deserializedData << std::endl;
    std::cout << "Contenu : " << deserializedData->id << " " << deserializedData->name << std::endl;

    if (deserializedData == &data)
        std::cout << "OK : meme pointeur" << std::endl;
    else
        std::cout << "KO : pointeurs differents" << std::endl;
    return 0;
}