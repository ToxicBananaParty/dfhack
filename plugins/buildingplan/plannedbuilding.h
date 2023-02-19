#pragma once

#include "buildingplan.h"

#include "Core.h"

#include "modules/Persistence.h"

#include "df/building.h"
#include "df/job_item_vector_id.h"

class PlannedBuilding {
public:
    const df::building::key_field_type id;

    // job_item idx -> list of vectors the task is linked to
    const std::vector<std::vector<df::job_item_vector_id>> vector_ids;

    const HeatSafety heat_safety;

    PlannedBuilding(DFHack::color_ostream &out, df::building *bld, HeatSafety heat);
    PlannedBuilding(DFHack::color_ostream &out, DFHack::PersistentDataItem &bld_config);

    void remove(DFHack::color_ostream &out);

    // Ensure the building still exists and is in a valid state. It can disappear
    // for lots of reasons, such as running the game with the buildingplan plugin
    // disabled, manually removing the building, modifying it via the API, etc.
    df::building * getBuildingIfValidOrRemoveIfNot(DFHack::color_ostream &out);

private:
    DFHack::PersistentDataItem bld_config;
};
