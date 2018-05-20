#pragma once

using ip_adress = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

enum class FILTER_MATCH { ANY_OF, IN_ORDER };