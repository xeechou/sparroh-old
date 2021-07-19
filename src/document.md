## using diligent

An engine has its own traits, the diligent engine looks promissing, but it may
have traps like what you encounterred before.

### diligent-core
CMakeLists.txt handles platform settings, windows/linux/apple/android..., there
are around 400 lines of code, most of them are platform settings. There are two
types of macros:

- PLATFORM_{SPECIFIC}=1
- {GRAPHIC_API}_SUPPORTED=1

For example, we could have `PLATFORM_LINUX` and `VULKAN_SUPPORTED` set to one 

### Interface libraries

The two important interface library are `Diligent-PublicBuildSettings` and
`Diligent-BuildSettings`. They are a little confusing for sure, as their name
does not tell anything.

-  `Diligent-PublicBuildSettings`: compile definitions like `PLATFORM_` and
   `_SUPPORTED`
-  `Diligent-BuildSettings`: compilation flags, I can simply use this for
   linking my application.

### shader header fxh

Including fxh inside c++ is possible if you write compatible code, in diligent
engine, the header `BasicMath.h` need to be included before you include any
shader headers.

