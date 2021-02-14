#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

//An extremely simple png to ascii converter.
int main()
{

    std::string dark = "ÆÑÊŒØMÉËÈÃÂWQBÅæ#NÁşEÄÀHKRœXgĞêqÛŠÕÔA€ßpmãâG¶øğé8ÚÜ$ëdÙıèÓŞÖåÿÒb¥FDñáZPäšÇàhû§İkŸ®S9UTe6µOyxÎ¾f4õ5ôú&aü™2ùçw©Y£0VÍL±3ÏÌóC@nöòs¢u‰½¼‡zJƒ%¤Itocîrjv1lí=ïì<>i7†[¿?×}*{+()/»«•¬|!¡÷¦¯—^ª„”“~³º²–°­¹‹›;:’‘‚’˜ˆ¸…·¨´`";
    std::vector<char> asciiChars = {};
    for (unsigned int i = 0; i < dark.size(); i++) {
        asciiChars.push_back(dark[i]);
    }
    sf::Image img;
    std::string source, destination;
    std::cout << "Picture location: ";
    std::cin >> source;
    std::cout << "\nWhere do you want to save it?(type in null character for default): ";
    std::cin >> destination;
    if (!img.loadFromFile(source))
    {
        std::cout << "Error!" << std::endl;
    }
    else
    {
        std::string text;
        sf::Vector2u size = img.getSize();
        for (unsigned int i = 0; i < size.x; i++) {
            text.push_back('\n');
            for (unsigned int j = 0; j < size.y; j++) {
                int l = int(img.getPixel(j, i).r * 0.2126 + img.getPixel(j, i).g * 0.7152 + img.getPixel(j, i).b * 0.0722);
                text.push_back(asciiChars[l % asciiChars.size()]);
            }
        }

        std::ofstream outfile;
        if (!destination.empty())
        {
            outfile.open(destination + "\\ascii.txt");
        }
        else {
            std::cout << "Saving in default" << std::endl;
            outfile.open("ascii.txt");
        }
        outfile << text << std::endl;
        outfile.close();
        std::cout << "Done" << std::endl;
    }

    return 0;
}