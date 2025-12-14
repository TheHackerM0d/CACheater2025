namespace cheat
{
    namespace visual
    {
        bool NxChams = false;
        bool NoFog = false;
        bool NoSmoke = false;
        bool ScreenGlow = false;
        bool RemoveTexture = false;
        bool FullBrights = false;
        bool WorldBox = false;
        bool WorldTree = false;
        bool Tracer = false;
    }
    namespace player
    {
        bool knockback = false;
        bool Fly = false;
    }
    namespace special
    {
        bool KickHack = false;
        bool RadioSpam = false;
    }
    namespace esp
    {
        namespace Ennemy
        {
            bool Activation = false;

            bool Lines = false;
            bool Box = false;

            bool Health = false;

            float Visible[3] = { 1.0f, 0.0f, 0.0f };     // Rouge
            float NonVisible[3] = { 0.6f, 0.0f, 0.0f };  // Rouge foncé
            float Respawn[3] = { 1.0f, 1.0f, 1.0f };  // Rouge foncé
        }
        namespace Allies
        {
            bool Activation = false;

            bool Lines = false;
            bool Box = false;

            bool Health = false;

            float Visible[3] = { 0.0f, 1.0f, 0.0f };   // Vert vif
            float NonVisible[3] = { 0.0f, 0.5f, 0.0f };   // Vert foncé
            float Respawn[3] = { 1.0f, 1.0f, 1.0f };   // Vert foncé
        }
    }
    namespace aimbot
    {
        bool Activation = false;
        //Player
        bool SmoothAim = true;
        //float
        float SmoothMax = 1.0f;
        float SmoothMin = 0.4f;
        //int
        int AimBone = 0;
        int AimFov = 1;
        int AimKey = 1;
        namespace Ghost
        {
            namespace Radius
            {
                bool Activation = false;
            }
        }
    }
    namespace spoofer
    {
        namespace cosmetic
        {
            bool Activation = false;

            bool Character = false;
            int CharacterID = false;
            
            bool Helmet = false;
            int HelmetID = false;
            
            namespace Backup
            {
                bool DefaultCharacterMode = false;
                int DefaultCharacter[20];
            }
        }
    }
}
namespace ModMenu
{
    bool LoggingAddress = true;
    bool Activity = false; 
    namespace MenuDesign
    {
        int Theme = 0;
    }
}