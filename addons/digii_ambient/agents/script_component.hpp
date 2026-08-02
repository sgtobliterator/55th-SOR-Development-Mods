#define COMPONENT agents
#define COMPONENT_BEAUTIFIED Agents
#include "\z\digii_ambient\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_AGENTS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_AGENTS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_AGENTS
#endif

#include "\z\digii_ambient\addons\main\script_macros.hpp"

// Spawn tunables
#define PER_ZONE_CAP 30
#define GLOBAL_CAP 200
#define SPAWN_DENSITY_DIVISOR 15
#define GARRISON_MAX_UNITS_PER_BUILDING 20

// Civilian "at-home" residents per building. Lower than the military
// cap because residents represent a household, not a defending squad.
#define CIVILIAN_GARRISON_MAX_UNITS_PER_BUILDING 3

// Patrol cycle: N MOVE waypoints around the zone + one CYCLE closer.
#define PATROL_WAYPOINT_COUNT 5

// Patrol group sizing: each PATROL slot becomes a group of [MIN..MAX] units
// (random per group) clustered within CLUSTER_RADIUS of one random in-zone
// pick. Mirrors the garrison semantic: 1 slot = 1 group of N units.
#define PATROL_GROUP_MIN_UNITS 2
#define PATROL_GROUP_MAX_UNITS 4
#define PATROL_CLUSTER_RADIUS 5

// Wanderer cadence: each lone wanderer picks a new random target every
// [MIN..MAX] seconds via doMove. Long pauses at the destination feel more
// natural than constant motion and let units actually arrive before
// re-targeting. Self-rescheduling via CBA_fnc_waitAndExecute; no per-unit
// PFH tracking required.
#define WANDERER_PAUSE_MIN 10
#define WANDERER_PAUSE_MAX 30

// Civilian threat system tunables. Per-civilian `digii_ambient_threat`
// climbs on nearby gunfire / death events (0.0..1.0, stepped 0.1) and
// decays via a self-rescheduling tick. Step 14 populates the value;
// Step 15 will read it to drive behavior.
#define THREAT_TICK_INTERVAL   10      // seconds between decay ticks
#define THREAT_DECAY_PER_TICK  0.1    // subtracted from threat each tick
#define THREAT_GUNFIRE_RADIUS  80     // m; FiredNear distance gate
#define THREAT_GUNFIRE_STEP    0.3    // added per qualifying FiredNear event
#define THREAT_DEATH_RADIUS    30     // m; bystander panic radius on death
#define THREAT_DEATH_STEP      0.5    // added to neighbors on civilian death

// Threat band boundaries. CALM = [0.0, ALERT), ALERT = [ALERT, PANIC),
// PANIC = [PANIC, 1.0]. Edge-triggered dispatch lives in fnc_threatTick;
// the per-role state for each band is applied by fnc_applyThreatBand.
#define THREAT_BAND_ALERT      0.4    // lower bound of ALERT band
#define THREAT_BAND_PANIC      0.7    // lower bound of PANIC band
#define COVER_SEARCH_RADIUS    50     // m; max search distance for flee cover
#define COVER_SNAP_DELAY       8      // seconds after PANIC doMove before snap-into-cover fallback

// Role identifiers. Stored on each unit via setVariable "digii_ambient_role".
// Used by fnc_distributeRoles to label spawn slots; behavior loops in later
// steps dispatch on these values.
#define ROLE_GUARD          "GUARD"
#define ROLE_PATROL         "PATROL"
#define ROLE_IDLER          "IDLER"
#define ROLE_WANDERER       "WANDERER"
#define ROLE_OFFICER        "OFFICER"
#define ROLE_CIV_GARRISON   "CIV_GARRISON"

// Looping idle animations used by the IDLER role. Each Idler picks one
// randomly at spawn via switchMove. switchMove silently no-ops if a class
// is missing on the player's Arma build, so this list is safe to extend.
#define IDLE_ANIMS [\
    "HubStanding_idle_v1",\
    "HubStanding_idle_v2",\
    "HubStanding_idle_v3",\
    "Acts_AidlPercMstpSnonWnonDnon_in",\
    "Acts_AidlPercMstpSlowWrflDnon_in",\
    "Acts_AidlPercMstpSrasWrflDnon_in"\
]
