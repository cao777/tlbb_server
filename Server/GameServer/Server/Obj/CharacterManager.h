// CharacterManager.h
// 
//////////////////////////////////////////////////////

#ifndef __CHARACTERMANAGER_H__
#define __CHARACTERMANAGER_H__

#include "Type.h"
#include "Obj_Character.h"


class Scene;
class Packet;
class CharacterManager
{
public :
	CharacterManager( ) ;
	~CharacterManager( ) ;

	virtual VOID	CleanUp( ) ;

	virtual BOOL	AddCharacter( Obj_Character* pCharacter ) ;
	virtual BOOL	DelCharacter( ObjID_t ObjID ) ;

	Obj_Character*	GetCharacter( ObjID_t ObjID ) ;

	virtual BOOL	KillCharacter( Obj_Character* pCharacter ) ;
	virtual BOOL	HeartBeat( UINT uTime=0 ) ;

	BOOL			BroadCast( Packet* pPacket, Obj_Character* pOwn ) ;

	uint			GetCount( ){ return m_Count ; } ;

	VOID			SetScene( Scene* pScene )
	{ 
		Assert( pScene ) ;
		m_pScene = pScene ; 
	} ;
	Scene*			GetScene(){ return m_pScene ; } ;

private :
	BOOL			Resize( uint iSize ) ;


private :
	ObjID_t*		m_pObjIDs ;
	uint			m_TotalSize ;
	uint			m_Count ;

	Scene*			m_pScene ;


};



#endif
