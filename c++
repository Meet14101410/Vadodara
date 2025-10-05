#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Represents a major landmark or point of interest
struct Landmark {
    std::string name;
    std::string type;
    std::string description;
};

// Manages information about Vadodara
class VadodaraInfoSystem {
private:
    std::unordered_map<std::string, std::string> city_facts;
    std::vector<Landmark> points_of_interest;

public:
    VadodaraInfoSystem() {
        city_facts["Location"] = "Gujarat, India (on the banks of the Vishwamitri River)";
        city_facts["Population"] = "Approx. 2.2 million (2023)";
        city_facts["Known For"] = "Cultural Capital of Gujarat, seat of the Gaekwad dynasty, and M.S. University.";

        points_of_interest.push_back({"Laxmi Vilas Palace", "Royal Residence", "A magnificent 19th-century palace, still the residence of the royal Gaekwad family."});
        points_of_interest.push_back({"Sayaji Baug (Kamati Baug)", "Public Park", "A large public park housing a museum, zoo, and an aquarium."});
        points_of_interest.push_back({"EME Temple", "Religious Site", "A unique temple managed by the Indian Army's EME wing, famous for its aluminum sheet architecture."});
    }

    void get_city_fact(const std::string& fact_name) const {
        if (city_facts.count(fact_name)) {
            std::cout << fact_name << ": " << city_facts.at(fact_name) << std::endl;
        } else {
            std::cout << "Fact not found: " << fact_name << std::endl;
        }
    }
    
    void search_landmarks(const std::string& search_term) const {
        std::cout << "\n--- Search Results for '" << search_term << "' ---" << std::endl;
        bool found = false;
        std::string lower_search_term = search_term;
        std::transform(lower_search_term.begin(), lower_search_term.end(), lower_search_term.begin(), ::tolower);

        for (const auto& landmark : points_of_interest) {
            std::string lower_name = landmark.name;
            std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
            
            if (lower_name.find(lower_search_term) != std::string::npos || 
                landmark.type.find(search_term) != std::string::npos) {
                std::cout << "Name: " << landmark.name << std::endl;
                std::cout << "Type: " << landmark.type << std::endl;
                std::cout << "Description: " << landmark.description << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No matching landmarks found." << std::endl;
        }
    }
};

int main() {
    VadodaraInfoSystem info_system;
    
    // Display general facts
    info_system.get_city_fact("Population");
    info_system.get_city_fact("Known For");

    // Search for landmarks
    info_system.search_landmarks("Palace");
    info_system.search_landmarks("Park");

    return 0;
}
