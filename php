<?php

class VadodaraInfoSystem {
    private $city_facts;
    private $points_of_interest;

    public function __construct() {
        $this->city_facts = [
            "Location" => "Gujarat, India (on the banks of the Vishwamitri River)",
            "Population" => "Approx. 2.2 million (2023)",
            "Known For" => "Cultural Capital of Gujarat, seat of the Gaekwad dynasty, and M.S. University."
        ];
        
        $this->points_of_interest = [
            [
                "name" => "Laxmi Vilas Palace",
                "type" => "Royal Residence",
                "description" => "A magnificent 19th-century palace, still the residence of the royal Gaekwad family."
            ],
            [
                "name" => "Sayaji Baug (Kamati Baug)",
                "type" => "Public Park",
                "description" => "A large public park housing a museum, zoo, and an aquarium."
            ],
            [
                "name" => "EME Temple",
                "type" => "Religious Site",
                "description" => "A unique temple managed by the Indian Army's EME wing, famous for its aluminum sheet architecture."
            ]
        ];
    }

    public function getCityFact($fact_name) {
        if (isset($this->city_facts[$fact_name])) {
            return "<strong>" . htmlspecialchars($fact_name) . "</strong>: " . htmlspecialchars($this->city_facts[$fact_name]);
        } else {
            return "Fact not found: " . htmlspecialchars($fact_name);
        }
    }

    public function searchPointsOfInterest($search_term) {
        $found_pois = [];
        $lower_search_term = strtolower($search_term);

        foreach ($this->points_of_interest as $poi) {
            // Search by name or type
            if (strpos(strtolower($poi["name"]), $lower_search_term) !== false || strpos(strtolower($poi["type"]), $lower_search_term) !== false) {
                $found_pois[] = $poi;
            }
        }
        return $found_pois;
    }
}

// Example usage
$info_system = new VadodaraInfoSystem();

echo "<h2>Vadodara City Facts</h2>";
echo "<p>" . $info_system->getCityFact("Location") . "</p>";
echo "<p>" . $info_system->getCityFact("Known For") . "</p>";

echo "<h2>Searching for 'Park'</h2>";
$park_results = $info_system->searchPointsOfInterest("Park");
if (!empty($park_results)) {
    foreach ($park_results as $result) {
        echo "<p><strong>Name</strong>: " . htmlspecialchars($result["name"]) . "</p>";
        echo "<p><strong>Type</strong>: " . htmlspecialchars($result["type"]) . "</p>";
        echo "<p><strong>Description</strong>: " . htmlspecialchars($result["description"]) . "</p>";
        echo "<hr>";
    }
} else {
    echo "<p>No matching points of interest found.</p>";
}

?>
