#include <iostream>
#include <fstream>

void skip(std::ifstream* infile, int count) {
    for (int i = 0; i < count; i++) {
        infile->get();
    }
}

void jpeg_to_stif(std::string input, std::string output) {
    std::ofstream outfile(output, std::ios::binary | std::ios::out);
    std::ifstream infile(input, std::ios::binary | std::ios::in);

    skip(&infile, 2); // Skip SOI Segment
    skip(&infile, 18); // Skip APP0 Segment
    skip(&infile, 69 * 2); // Skip 2 DQT Segments
    skip(&infile, 19); // Skip SOF Segment
    skip(&infile, 23); // Skip first DHT Segment
    skip(&infile, 27); // Skip second DHT Segment
    skip(&infile, 23); // Skip third DHT Segment
    skip(&infile, 30); // Skip fourth DHT Segment
    skip(&infile, 14); // Skip SOS Segment

    int data[4] = {45, 46, 47, 48};

    outfile.write((char*) &data, sizeof(data));
    outfile.close();
}
