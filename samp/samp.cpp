#include "fakeamx.h"
#include "jump.h"
#include "samp.h"
#include "wrapper.h"

#define PARAMS(n) ((n) * sizeof(cell))

#ifdef _MSC_VER
    #pragma warning(push)
    // forcing value to bool 'true' or 'false' (performance warning)
    #pragma warning(disable: 4800)
#endif

namespace samp {

bool SendClientMessage(int playerid, long color, const std::string &message) {
    static auto native = Wrapper::GetInstance()->GetNative("SendClientMessage");
    cstring message_(message.begin(), message.end());
    cell params[] = {
        PARAMS(3),
        playerid,
        color,
        reinterpret_cast<cell>(message_.c_str())
    };
    return native(&::fakeAmx, params);
}

void SendClientMessageToAll(long color, const std::string &message) {
    static auto native = Wrapper::GetInstance()->GetNative("SendClientMessageToAll");
    cstring message_(message.begin(), message.end());
    cell params[] = {
        PARAMS(2),
        color,
        reinterpret_cast<cell>(message_.c_str())
    };
    native(&::fakeAmx, params);
}

bool SendPlayerMessageToPlayer(int playerid, int senderid, const std::string &message) {
    static auto native = Wrapper::GetInstance()->GetNative("SendPlayerMessageToPlayer");
    cstring message_(message.begin(), message.end());
    cell params[] = {
        PARAMS(3),
        playerid,
        senderid,
        reinterpret_cast<cell>(message_.c_str())
    };
    return native(&::fakeAmx, params);
}

bool SendPlayerMessageToAll(int senderid, const std::string &message) {
    static auto native = Wrapper::GetInstance()->GetNative("SendPlayerMessageToAll");
    cstring message_(message.begin(), message.end());
    cell params[] = {
        PARAMS(2),
        senderid,
        reinterpret_cast<cell>(message_.c_str())
    };
    return native(&::fakeAmx, params);
}

bool SendDeathMessage(int killer, int killee, int weapon) {
    static auto native = Wrapper::GetInstance()->GetNative("SendDeathMessage");
    cell params[] = {
        PARAMS(3),
        killer,
        killee,
        weapon
    };
    return native(&::fakeAmx, params);
}

bool GameTextForAll(const std::string &text, long time, int style) {
    static auto native = Wrapper::GetInstance()->GetNative("GameTextForAll");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(3),
        reinterpret_cast<cell>(text_.c_str()),
        time,
        style
    };
    return native(&::fakeAmx, params);
}

bool GameTextForPlayer(int playerid, const std::string &text, long time, int style) {
    static auto native = Wrapper::GetInstance()->GetNative("GameTextForPlayer");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(4),
        playerid,
        reinterpret_cast<cell>(text_.c_str()),
        time,
        style
    };
    return native(&::fakeAmx, params);
}

long GetTickCount() {
    static auto native = Wrapper::GetInstance()->GetNative("GetTickCount");
    return native(&::fakeAmx, 0);
}

int GetMaxPlayers() {
    static auto native = Wrapper::GetInstance()->GetNative("GetMaxPlayers");
    return native(&::fakeAmx, 0);
}

void SetGameModeText(const std::string &text) {
    static auto native = Wrapper::GetInstance()->GetNative("SetGameModeText");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(1), 
        reinterpret_cast<cell>(text_.c_str())
    };
    native(&::fakeAmx, params);
}

void SetTeamCount(int count) {
    static auto native = Wrapper::GetInstance()->GetNative("SetTeamCount");
    cell params[] = {
        PARAMS(1), 
        count
    };
    native(&::fakeAmx, params);
}

int AddPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, 
    int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) 
{
    static auto native = Wrapper::GetInstance()->GetNative("AddPlayerClass");
    cell params[] = {
        PARAMS(11), 
        modelid,
        amx_ftoc(spawn_x),
        amx_ftoc(spawn_y),
        amx_ftoc(spawn_z),
        amx_ftoc(z_angle),
        weapon1,
        weapon1_ammo,
        weapon2,
        weapon2_ammo,
        weapon3,
        weapon3_ammo
    };
    return native(&::fakeAmx, params);
}

int AddPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, 
    int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo)
{
    static auto native = Wrapper::GetInstance()->GetNative("AddPlayerClassEx");
    cell params[] = {
        PARAMS(12), 
        teamid,
        modelid,
        amx_ftoc(spawn_x),
        amx_ftoc(spawn_y),
        amx_ftoc(spawn_z),
        amx_ftoc(z_angle),
        weapon1,
        weapon1_ammo,
        weapon2,
        weapon2_ammo,
        weapon3,
        weapon3_ammo
    };
    return native(&::fakeAmx, params);
}

int AddStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, 
    long color1, long color2)
{
    static auto native = Wrapper::GetInstance()->GetNative("AddStaticVehicle");
    cell params[] = {
        PARAMS(7), 
        modelid,
        amx_ftoc(spawn_x),
        amx_ftoc(spawn_y),
        amx_ftoc(spawn_z),
        amx_ftoc(z_angle),
        color1,
        color2
    };
    return native(&::fakeAmx, params);
}

int AddStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, 
    long color1, long color2, long respawn_delay) 
{
    static auto native = Wrapper::GetInstance()->GetNative("AddStaticVehicleEx");
    cell params[] = {
        PARAMS(8), 
        modelid,
        amx_ftoc(spawn_x),
        amx_ftoc(spawn_y),
        amx_ftoc(spawn_z),
        amx_ftoc(z_angle),
        color1,
        color2,
        respawn_delay
    };
    return native(&::fakeAmx, params);
}

int AddStaticPickup(int model, int type, float x, float y, float z, long virtualworld) {
    static auto native = Wrapper::GetInstance()->GetNative("AddStaticPickup");
    cell params[] = {
        PARAMS(6), 
        model,
        type,
        amx_ftoc(x),
        amx_ftoc(y),
        amx_ftoc(z),
        virtualworld
    };
    return native(&::fakeAmx, params);
}

int CreatePickup(int model, int type, float x, float y, float z, long virtualworld) {
    static auto native = Wrapper::GetInstance()->GetNative("CreatePickup");
    cell params[] = {
        PARAMS(6), 
        model,
        type,
        amx_ftoc(x),
        amx_ftoc(y),
        amx_ftoc(z),
        virtualworld
    };
    return native(&::fakeAmx, params);
}

bool DestroyPickup(int pickup) {
    static auto native = Wrapper::GetInstance()->GetNative("DestroyPickup");
    cell params[] = {
        PARAMS(1),
        pickup
    };
    return native(&::fakeAmx, params);
}

void ShowNameTags(int show) {
    static auto native = Wrapper::GetInstance()->GetNative("ShowNameTags");
    cell params[] = {
        PARAMS(1),
        show
    };
    native(&::fakeAmx, params);
}

void ShowPlayerMarkers(int mode) {
    static auto native = Wrapper::GetInstance()->GetNative("ShowPlayerMarkers");
    cell params[] = {
        PARAMS(1),
        mode
    };
    native(&::fakeAmx, params);
}

void GameModeExit() {
    static auto native = Wrapper::GetInstance()->GetNative("GameModeExit");
    cell params[] = {
        PARAMS(0)
    };
    native(&::fakeAmx, params);
}

bool SetWorldTime(int hour) {
    static auto native = Wrapper::GetInstance()->GetNative("SetWorldTime");
    cell params[] = {
        PARAMS(1),
        hour
    };
    return native(&::fakeAmx, params);
}

std::string GetWeaponName(int weaponid) {
    static auto native = Wrapper::GetInstance()->GetNative("GetWeaponName");
    cstring name_(50, '\0'); // TODO: make max. length unlimited
    cell params[] = {
        PARAMS(3),
        weaponid,
        reinterpret_cast<cell>(name_.data()),
        name_.length()
    };
    native(&::fakeAmx, params);
    return std::string(name_.begin(), name_.end());
}

void EnableTirePopping(bool enable) {
    static auto native = Wrapper::GetInstance()->GetNative("EnableTirePopping");
    cell params[] = {
        PARAMS(1),
        enable
    };
    native(&::fakeAmx, params);
}

void AllowInteriorWeapons(bool allow) {
    static auto native = Wrapper::GetInstance()->GetNative("AllowInteriorWeapons");
    cell params[] = {
        PARAMS(1),
        allow
    };
    native(&::fakeAmx, params);
}

void SetWeather(int weatherid) {
    static auto native = Wrapper::GetInstance()->GetNative("SetWeather");
    cell params[] = {
        PARAMS(1),
        weatherid
    };
    native(&::fakeAmx, params);
}

void SetGravity(float gravity) {
    static auto native = Wrapper::GetInstance()->GetNative("SetGravity");
    cell params[] = {
        PARAMS(1),
        amx_ftoc(gravity)
    };
    native(&::fakeAmx, params);
}

void AllowAdminTeleport(bool allow) {
    static auto native = Wrapper::GetInstance()->GetNative("AllowAdminTeleport");
    cell params[] = {
        PARAMS(1),
        allow
    };
    native(&::fakeAmx, params);
}

void SetDeathDropAmount(long amount) {
    static auto native = Wrapper::GetInstance()->GetNative("SetDeathDropAmount");
    cell params[] = {
        PARAMS(1),
        amount
    };
    native(&::fakeAmx, params);
}

void CreateExplosion(float x, float y, float z, short type, float radius) {
    static auto native = Wrapper::GetInstance()->GetNative("CreateExplosion");
    cell params[] = {
        PARAMS(5), 
        amx_ftoc(x),
        amx_ftoc(y),
        amx_ftoc(z),
        type,
        amx_ftoc(radius)
    };
    native(&::fakeAmx, params);
}

void EnableZoneNames(bool enable) {
    static auto native = Wrapper::GetInstance()->GetNative("EnableZoneNames");
    cell params[] = {
        PARAMS(1),
        enable
    };
    native(&::fakeAmx, params);
}

void UsePlayerPedAnims() {
    static auto native = Wrapper::GetInstance()->GetNative("UsePlayerPedAnims");
    native(&::fakeAmx, 0);
}

void DisableInteriorEnterExits() {
    static auto native = Wrapper::GetInstance()->GetNative("DisableInteriorEnterExits");
    native(&::fakeAmx, 0);
}

void SetNameTagDrawDistance(float distance) {
    static auto native = Wrapper::GetInstance()->GetNative("SetNameTagDrawDistance");
    cell params[] = {
        PARAMS(1),
        amx_ftoc(distance)
    };
    native(&::fakeAmx, params);
}

void DisableNameTagLOS() {
    static auto native = Wrapper::GetInstance()->GetNative("DisableNameTagLOS");
    native(&::fakeAmx, 0);
}

void LimitGlobalChatRadius(float chat_radius) {
    static auto native = Wrapper::GetInstance()->GetNative("LimitGlobalChatRadius");
    cell params[] = {
        PARAMS(1),
        amx_ftoc(chat_radius)
    };
    native(&::fakeAmx, params);
}

void LimitPlayerMarkerRadius(float marker_radius) {
    static auto native = Wrapper::GetInstance()->GetNative("LimitPlayerMarkerRadius");
    cell params[] = {
        PARAMS(1),
        amx_ftoc(marker_radius)
    };
    native(&::fakeAmx, params);
}

bool ConnectNPC(const std::string &name, const std::string &script) {
    static auto native = Wrapper::GetInstance()->GetNative("ConnectNPC");
    cstring name_(name.begin(), name.end());
    cstring script_(script.begin(), script.end());
    cell params[] = {
        PARAMS(2),
        reinterpret_cast<cell>(name_.c_str()),
        reinterpret_cast<cell>(script_.c_str())
    };
    return native(&::fakeAmx, params);
}

bool IsPlayerNPC(int playerid) {
    static auto native = Wrapper::GetInstance()->GetNative("IsPlayerNPC");
    cell params[] = {
        PARAMS(1),
        playerid
    };
    return native(&::fakeAmx, params);
}

bool IsPlayerAdmin(int playerid) {
    static auto native = Wrapper::GetInstance()->GetNative("IsPlayerAdmin");
    cell params[] = {
        PARAMS(1),
        playerid
    };
    return native(&::fakeAmx, params);
}

bool Kick(int playerid) {
    static auto native = Wrapper::GetInstance()->GetNative("Kick");
    cell params[] = {
        PARAMS(1),
        playerid
    };
    return native(&::fakeAmx, params);
}

bool Ban(int playerid) {
    static auto native = Wrapper::GetInstance()->GetNative("Ban");
    cell params[] = {
        PARAMS(1),
        playerid
    };
    return native(&::fakeAmx, params);
}

bool BanEx(int playerid, const std::string &reason) {
    static auto native = Wrapper::GetInstance()->GetNative("BanEx");
    cell params[] = {
        PARAMS(1),
        playerid
    };
    return native(&::fakeAmx, params);
}

void SendRconCommand(const std::string &command) {
    static auto native = Wrapper::GetInstance()->GetNative("SendRconCommand");
    cstring command_(command.begin(), command.end());
    cell params[] = {
        PARAMS(1),
        reinterpret_cast<cell>(command_.c_str()),
    };
    native(&::fakeAmx, params);
}

std::string GetServerVarAsString(const std::string &varname) {
    static auto native = Wrapper::GetInstance()->GetNative("GetServerVarAsString");
    cstring varname_(varname.begin(), varname.end());
    cstring var_(128, '\0'); // TODO: make max. length unlimited
    cell params[] = {
        PARAMS(3),
        reinterpret_cast<cell>(varname_.c_str()),
        reinterpret_cast<cell>(var_.data()),
        var_.length()
    };
    native(&::fakeAmx, params);
    return std::string(var_.begin(), var_.end());
}

int GetServerVarAsInt(const std::string &varname) {
    static auto native = Wrapper::GetInstance()->GetNative("GetServerVarAsInt");
    cstring varname_(varname.begin(), varname.end());
    cell params[] = {
        PARAMS(1),
        reinterpret_cast<cell>(varname_.c_str())
    };
    return native(&::fakeAmx, params);
}

bool GetServerVarAsBool(const std::string &varname) {
    static auto native = Wrapper::GetInstance()->GetNative("GetServerVarAsBool");
    cstring varname_(varname.begin(), varname.end());
    cell params[] = {
        PARAMS(1),
        reinterpret_cast<cell>(varname_.c_str())
    };
    return native(&::fakeAmx, params);
}

int CreateMenu(const std::string &title, int columns, float x, float y, float col1width, float col2width) {
    static auto native = Wrapper::GetInstance()->GetNative("CreateMenu");
    cstring title_(title.begin(), title.end());
    cell params[] = {
        PARAMS(6),
        reinterpret_cast<cell>(title_.c_str()),
        columns,
        amx_ftoc(x),
        amx_ftoc(y),
        amx_ftoc(col1width),
        amx_ftoc(col2width)
    };
    return native(&::fakeAmx, params);
}

bool DestroyMenu(int menuid) {
    static auto native = Wrapper::GetInstance()->GetNative("DestroyMenu");
    cell params[] = {
        PARAMS(1),
        menuid
    };
    return native(&::fakeAmx, params);
}

int AddMenuItem(int menuid, int column, const std::string &menutext) {
    static auto native = Wrapper::GetInstance()->GetNative("AddMenuItem");
    cstring menutext_(menutext.begin(), menutext.end());
    cell params[] = {
        PARAMS(3),
        menuid,
        column,
        reinterpret_cast<cell>(menutext_.c_str())
    };
    return native(&::fakeAmx, params);
}

bool SetMenuColumnHeader(int menuid, int column, const std::string &columnheader) {
    static auto native = Wrapper::GetInstance()->GetNative("SetMenuColumnHeader");
    cstring columnheader_(columnheader.begin(), columnheader.end());
    cell params[] = {
        PARAMS(3),
        menuid,
        column,
        reinterpret_cast<cell>(columnheader_.c_str())
    };
    return native(&::fakeAmx, params);
}

bool ShowMenuForPlayer(int menuid, int playerid) {
    static auto native = Wrapper::GetInstance()->GetNative("ShowMenuForPlayer");
    cell params[] = {
        PARAMS(2),
        menuid,
        playerid
    };
    return native(&::fakeAmx, params);
}

bool HideMenuForPlayer(int menuid, int playerid) {
    static auto native = Wrapper::GetInstance()->GetNative("HideMenuForPlayer");
    cell params[] = {
        PARAMS(2),
        menuid,
        playerid
    };
    return native(&::fakeAmx, params);
}

bool IsValidMenu(int menuid) {
    static auto native = Wrapper::GetInstance()->GetNative("IsValidMenu");
    cell params[] = {
        PARAMS(1),
        menuid
    };
    return native(&::fakeAmx, params);
}

bool DisableMenu(int menuid) {
    static auto native = Wrapper::GetInstance()->GetNative("DisableMenu");
    cell params[] = {
        PARAMS(1),
        menuid
    };
    return native(&::fakeAmx, params);
}

bool DisableMenuRow(int menuid, int row) {
    static auto native = Wrapper::GetInstance()->GetNative("DisableMenuRow");
    cell params[] = {
        PARAMS(2),
        menuid,
        row
    };
    return native(&::fakeAmx, params);
}

int GetPlayerMenu(int playerid) {
    static auto native = Wrapper::GetInstance()->GetNative("GetPlayerMenu");
    cell params[] = {
        PARAMS(1),
        playerid
    };
    return native(&::fakeAmx, params);
}

int TextDrawCreate(float x, float y, const std::string &text) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawCreate");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(3),
        amx_ftoc(x),
        amx_ftoc(y),
        reinterpret_cast<cell>(text_.c_str())
    };
    return native(&::fakeAmx, params);
}

bool TextDrawDestroy(int text) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawDestroy");
    cell params[] = {
        PARAMS(1),
        text
    };
    return native(&::fakeAmx, params);
}

bool TextDrawLetterSize(int text, float x, float y) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawLetterSize");
    cell params[] = {
        PARAMS(3),
        text,
        amx_ftoc(x),
        amx_ftoc(y)
    };
    return native(&::fakeAmx, params);
}

bool TextDrawTextSize(int text, float x, float y) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawTextSize");
    cell params[] = {
        PARAMS(3),
        text,
        amx_ftoc(x),
        amx_ftoc(y)
    };
    return native(&::fakeAmx, params);
}

bool TextDrawAlignment(int text, int alignment) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawAlignment");
    cell params[] = {
        PARAMS(2),
        text,
        alignment
    };
    return native(&::fakeAmx, params);
}

bool TextDrawColor(int text, long color) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawColor");
    cell params[] = {
        PARAMS(2),
        text,
        color
    };
    return native(&::fakeAmx, params);
}

bool TextDrawUseBox(int text, bool use) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawUseBox");
    cell params[] = {
        PARAMS(2),
        text,
        use
    };
    return native(&::fakeAmx, params);
}

bool TextDrawBoxColor(int text, long color) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawBoxColor");
    cell params[] = {
        PARAMS(2),
        text,
        color
    };
    return native(&::fakeAmx, params);
}

bool TextDrawSetShadow(int text, int size) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawSetShadow");
    cell params[] = {
        PARAMS(2),
        text,
        size
    };
    return native(&::fakeAmx, params);
}

bool TextDrawSetOutline(int text, int size) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawSetOutline");
    cell params[] = {
        PARAMS(2),
        text,
        size
    };
    return native(&::fakeAmx, params);
}

bool TextDrawBackgroundColor(int text, long color) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawBackgroundColor");
    cell params[] = {
        PARAMS(2),
        text,
        color
    };
    return native(&::fakeAmx, params);
}

bool TextDrawFont(int text, int font) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawFont");
    cell params[] = {
        PARAMS(2),
        text,
        font
    };
    return native(&::fakeAmx, params);
}

bool TextDrawSetProportional(int text, bool set) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawSetProportional");
    cell params[] = {
        PARAMS(2),
        text,
        set
    };
    return native(&::fakeAmx, params);
}

bool TextDrawShowForPlayer(int playerid, int text) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawShowForPlayer");
    cell params[] = {
        PARAMS(2),
        text,
        text
    };
    return native(&::fakeAmx, params);
}

bool TextDrawHideForPlayer(int playerid, int text) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawHideForPlayer");
    cell params[] = {
        PARAMS(2),
        playerid,
        text
    };
    return native(&::fakeAmx, params);
}

bool TextDrawShowForAll(int text) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawShowForAll");
    cell params[] = {
        PARAMS(1),
        text
    };
    return native(&::fakeAmx, params);
}

bool TextDrawHideForAll(int text) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawHideForAll");
    cell params[] = {
        PARAMS(1),
        text
    };
    return native(&::fakeAmx, params);
}

bool TextDrawSetString(int text, const std::string &string) {
    static auto native = Wrapper::GetInstance()->GetNative("TextDrawSetString");
    cstring string_(string.begin(), string.end());
    cell params[] = {
        PARAMS(2),
        text,
        reinterpret_cast<cell>(string_.c_str())
    };
    return native(&::fakeAmx, params);
}

int GangZoneCreate(float minx, float miny, float maxx, float maxy) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneCreate");
    cell params[] = {
        PARAMS(4),
        amx_ftoc(minx),
        amx_ftoc(miny),
        amx_ftoc(maxx),
        amx_ftoc(maxy)
    };
    return native(&::fakeAmx, params);
}

bool GangZoneDestroy(int zone) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneDestroy");
    cell params[] = {
        PARAMS(1),
        zone
    };
    return native(&::fakeAmx, params);
}

bool GangZoneShowForPlayer(int playerid, int zone, long color) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneShowForPlayer");
    cell params[] = {
        PARAMS(3),
        playerid,
        zone,
        color
    };
    return native(&::fakeAmx, params);
}

bool GangZoneShowForAll(int zone, long color) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneShowForAll");
    cell params[] = {
        PARAMS(2),
        zone,
        color
    };
    return native(&::fakeAmx, params);
}

bool GangZoneHideForPlayer(int playerid, int zone) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneHideForPlayer");
    cell params[] = {
        PARAMS(2),
        playerid,
        zone
    };
    return native(&::fakeAmx, params);
}

bool GangZoneHideForAll(int zone) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneHideForAll");
    cell params[] = {
        PARAMS(1),
        zone
    };
    return native(&::fakeAmx, params);
}

bool GangZoneFlashForPlayer(int playerid, int zone, long flashcolor) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneFlashForPlayer");
    cell params[] = {
        PARAMS(3),
        playerid,
        zone,
        flashcolor
    };
    return native(&::fakeAmx, params);
}

bool GangZoneFlashForAll(int zone, long flashcolor) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneFlashForAll");
    cell params[] = {
        PARAMS(2),
        zone,
        flashcolor
    };
    return native(&::fakeAmx, params);
}

bool GangZoneStopFlashForPlayer(int playerid, int zone) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneStopFlashForPlayer");
    cell params[] = {
        PARAMS(2),
        playerid,
        zone
    };
    return native(&::fakeAmx, params);
}

bool GangZoneStopFlashForAll(int zone) {
    static auto native = Wrapper::GetInstance()->GetNative("GangZoneStopFlashForAll");
    cell params[] = {
        PARAMS(1),
        zone
    };
    return native(&::fakeAmx, params);
}

int Create3DTextLabel(const std::string &text, long color, float x, float y, float z, float DrawDistance, long virtualworld, bool testLOS) {
    static auto native = Wrapper::GetInstance()->GetNative("Create3DTextLabel");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(8),
        reinterpret_cast<cell>(text_.c_str()),
        color,
        amx_ftoc(x),
        amx_ftoc(y),
        amx_ftoc(z),
        amx_ftoc(DrawDistance),
        virtualworld,
        testLOS
    };
    return native(&::fakeAmx, params);
}

bool Delete3DTextLabel(int id) {
    static auto native = Wrapper::GetInstance()->GetNative("Delete3DTextLabel");
    cell params[] = {
        PARAMS(1),
        id
    };
    return native(&::fakeAmx, params);
}

bool Attach3DTextLabelToPlayer(int id, int playerid, float OffsetX, float OffsetY, float OffsetZ) {
    static auto native = Wrapper::GetInstance()->GetNative("Attach3DTextLabelToPlayer");
    cell params[] = {
        PARAMS(5),
        id,
        playerid,
        amx_ftoc(OffsetX),
        amx_ftoc(OffsetY),
        amx_ftoc(OffsetZ)
    };
    return native(&::fakeAmx, params);
}

bool Attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX, float OffsetY, float OffsetZ) {
    static auto native = Wrapper::GetInstance()->GetNative("Attach3DTextLabelToVehicle");
    cell params[] = {
        PARAMS(5),
        id,
        vehicleid,
        amx_ftoc(OffsetX),
        amx_ftoc(OffsetY),
        amx_ftoc(OffsetZ)
    };
    return native(&::fakeAmx, params);
}

bool Update3DTextLabelText(int id, long color, const std::string &text) {
    static auto native = Wrapper::GetInstance()->GetNative("Update3DTextLabelText");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(3),
        id,
        color,
        reinterpret_cast<cell>(text_.c_str())
    };
    return native(&::fakeAmx, params);
}

int CreatePlayer3DTextLabel(int playerid, const std::string &text, long color, float x, float y, float z, float DrawDistance, int attachedplayer, int attachedvehicle, bool testLOS) {
    static auto native = Wrapper::GetInstance()->GetNative("CreatePlayer3DTextLabel");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(10),
        playerid,
        reinterpret_cast<cell>(text_.c_str()),
        color,
        amx_ftoc(x),
        amx_ftoc(y),
        amx_ftoc(z),
        amx_ftoc(DrawDistance),
        attachedplayer,
        attachedvehicle,
        testLOS
    };
    return native(&::fakeAmx, params);
}

bool DeletePlayer3DTextLabel(int playerid, int id) {
    static auto native = Wrapper::GetInstance()->GetNative("DeletePlayer3DTextLabel");
    cell params[] = {
        PARAMS(2),
        playerid,
        id
    };
    return native(&::fakeAmx, params);
}

bool UpdatePlayer3DTextLabelText(int playerid, int id, long color, const std::string &text) {
    static auto native = Wrapper::GetInstance()->GetNative("UpdatePlayer3DTextLabelText");
    cstring text_(text.begin(), text.end());
    cell params[] = {
        PARAMS(4),
        playerid,
        id,
        color,
        reinterpret_cast<cell>(text_.c_str())
    };
    return native(&::fakeAmx, params);
}

} // namespace samp