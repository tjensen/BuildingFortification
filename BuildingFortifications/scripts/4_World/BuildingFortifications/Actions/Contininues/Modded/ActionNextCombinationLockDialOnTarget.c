modded class ActionNextCombinationLockDialOnTarget
{
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        if (super.ActionCondition(player, target, item)) return true;

        if (!target.GetObject()) return false;

        CombinationLock lock = CombinationLock.Cast( target.GetObject() );
        if (!lock) return false;

        EntityAI parent = lock.GetHierarchyParent();
        if (!parent) return false;

        if ( BuildingFortficationsCore.Cast(lock.GetHierarchyParent()) )
        {
            ConstructionActionData construction_action_data = player.GetConstructionActionData();
            construction_action_data.SetCombinationLock( lock );
            construction_action_data.SetCombinationLockSide(-1);
            return true;
        }

        return false;
    }
}
