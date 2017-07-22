/*
**
*/
#if defined _PARTICLES_included
 #endinput
#endif
#define _PARTICLES_included
#include <thelpers/thelpers>
#define PARTICLE_SYSTEM_CLASSNAME	"info_particle_system"
#define INVALID_PARTICLE_SYSTEM		view_as<CParticleSystem>(INVALID_ENTITY)

methodmap CParticleSystem < CBaseEntity {
	public static CParticleSystem UpCast(CBaseEntity i_ent)
	{
		char s_classname[] = PARTICLE_SYSTEM_CLASSNAME;
		if (!i_ent.GetClassname(s_classname, sizeof(s_classname)))
		{
			return INVALID_PARTICLE_SYSTEM;
		}
		if (!StrEqual(s_classname, PARTICLE_SYSTEM_CLASSNAME))
		{
			return INVALID_PARTICLE_SYSTEM;
		}
		return view_as<CParticleSystem>(i_ent);
	}
	
	public CParticleSystem(int i_ent_index)
	{
		CBaseEntity i_ent = new CBaseEntity(i_ent_index);
		if (i_ent == INVALID_ENTITY)
		{
			return INVALID_PARTICLE_SYSTEM;
		}
		return CParticleSystem.UpCast(i_ent);
	}
	
	public bool Start()
	{
		return this.AcceptInput("Start");
	}
	
	public bool Stop()
	{
		return this.AcceptInput("Stop");
	}
	
	public bool Kill()
	{
		return this.AcceptInput("Kill");
	}
	
	public void Activate()
	{
		ActivateEntity(this.Ref);
	}
	
	public bool SetEffectName(const char[] s_effect_name)
	{
		return this.KeyValue("effect_name", s_effect_name);
	}
	
	public static CParticleSystem Create(int i_force_edict_index = -1)
	{
		CBaseEntity i_ent = CBaseEntity.CreateByName(PARTICLE_SYSTEM_CLASSNAME, i_force_edict_index);
		return CParticleSystem.UpCast(i_ent);
	}
}