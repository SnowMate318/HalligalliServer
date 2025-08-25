#include "RoomInfoMessage.h"

json RoomInfoMessage::toJson()
{
    json j;

    j["page"] = page;
    j["rooms"] = json::array();

    for (IRoom* r : rooms) {
        if (!r) continue;
        j["rooms"].push_back({
            {"room_id",   r->getRoomId()},  // ��: int
            {"room_title",r->getRoomName() }   // ��: std::string
            });
    }
    return j;
}
