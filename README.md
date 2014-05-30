# TrueCrypt Source

## What

I've wanted a collection of the TrueCrypt source in a way that could be
diffed and browsed easily. TrueCrypt has been released as only source 
zips/tarballs over the years, so there's no native repository to look
through. It's been packaged inconsistently, to boot, which is annoying
as well.

So here's a basic repository with all (well, most) of the source.


## Where

The TrueCrypt developers seem to have gone back and forth several times
on which files should be included in the zip/tar bundles. To keep the
change history easily browsable, I've created two branches, "windows" and
"unix", with their associated collections of code. The master branch has
nothing on it directly.

Each release has a tag, "truecrypt-M.m" or "truecrypt-M.m-unix"

(A few versions are missing due to the original tar/zip being unavailable)


## Specifics

Built from the following files (with their associated sha1 hashes):

    7d4980c01de6bb8a591b6ef5c7518ef06ba4850a  truecrypt-1.0-source-code.zip
    a8bf043d5111379bd5075f09f9238b3b580d2e65  truecrypt-1.0a-source-code.zip
    aadbd3fea0ee540642d56e420ecfaae0a5d549e0  truecrypt-2.0-source-code.zip
    d0543b6ac4ee84d7d1e4ba24fc8843628d40c5e4  truecrypt-2.1-source-code.zip
    ebb2f2f111769def8811d0f905a258d751bf535a  truecrypt-2.1a-source-code.zip
    c77f6f75bbbec4f9eb66be0dd0e8f96624a8cf2a  truecrypt-3.0a-source-code.zip
    e801264529544b4f5d80f369df32c9d97a21c3d6  truecrypt-3.1-source-code.zip
    93a96c280ad1db256d22096213f730d32dd70225  truecrypt-3.1a-source-code.zip
    d6f1789cba168b21a79f89ee62e822af680f066a  truecrypt-4.0-source-code.tar.gz
    1685b06657031b6b94a941480bbf792b091f0e6e  truecrypt-4.0-source-code.zip
    d9f7fce586b6e671663855b8a02f23927800f5d2  truecrypt-4.1-source-code.tar.gz
    3c6219bddf4fb5b147a465c0f37ea777461c2dce  truecrypt-4.1-source-code.zip
    603bac50891c49b051f7a9bcc15b1196168bff2a  truecrypt-4.2-source-code.tar.gz
    403c960b5cd452656c0b55d739e91a8395e4d226  truecrypt-4.2-source-code.zip
    915a8771f9a76d06f5071ca07f5fe902a7f26575  truecrypt-4.2a-source-code.tar.gz
    0b44439f50bb35269098d33083e22aab40d298bf  truecrypt-4.2a-source-code.zip
    42754b3c192edb94880c97ca5453558738bf2cb1  truecrypt-4.3-source-code.tar.gz
    30c91901171c3c8290d4d0de856774cdf7ee4ed6  truecrypt-4.3a-source-code.tar.gz
    e57c8d59e04992ed4be19335f38084e42e08d44f  truecrypt-4.3a-source-code.zip
    f6e71f757425cedc76f023a91b78a073e279cdac  TrueCrypt 5.0 Source.tar.gz
    1d98f8e7130565bb73f525a8f4bba9b766315ad3  TrueCrypt 5.0 Source.zip
    793768704161e9b7a70cd82d691896ca4fc6f988  TrueCrypt 5.0a Source.tar.gz
    5e1a88e101d601b77aa4c9f3451ab1535464664a  TrueCrypt 5.0a Source.zip
    a3f56fae9ee34be51a87fa9c918069471672d38f  TrueCrypt 5.1 Source.tar.gz
    9bd6abeb2911a612db02d82ecda4ba4a111989aa  TrueCrypt 5.1 source.zip
    5453b855036f09361c5b970d4cd3069e62a7221b  TrueCrypt 5.1a Source.tar.gz
    6365b19105873f5bf4e86a6228c63bdf5524cdfa  TrueCrypt 5.1a Source.zip
    767c81c18edff858bfe8c26c455e76626609b577  TrueCrypt 6.0 Source.tar.gz
    fc81ea593c6555278c94b62a4e9ac8c73dd5069b  TrueCrypt 6.0 Source.zip
    5ebfe6a79620ced63e6eb33f2cbff6dfa5fd57e9  TrueCrypt 6.0a Source.tar.gz
    b8f3c5c9112399001d9d51f36f1204910efbd124  TrueCrypt 6.0a Source.zip
    f8996c35f4724b3c247c89ca59a0aff471bbb702  TrueCrypt 6.1 Source.tar.gz
    268dab57a6eb9bb84c9fe22d9fb612a84cd7759a  TrueCrypt 6.1 Source.zip
    f2fb1c8cd18b4452529edb53479418a5c1460a58  TrueCrypt 6.1a Source.tar.gz
    72aeec5791fe46ffe9e7726451796e3e4f0d099c  TrueCrypt 6.1a Source.zip
    a97ea8a68f10d38218d925a96f53de280d548abb  TrueCrypt 6.2 Source.tar.gz
    f829a33b46a404b33981c799d530e50a7b5a2587  TrueCrypt 6.2 Source.zip
    0aef417dc3caf449be6117258eac1644fccec9e3  TrueCrypt 6.2a Source.tar.gz
    2032aa51fabb6a98ac2943e0845f3021242ba556  TrueCrypt 6.2a Source.zip
    2f85f54b80f803844a452f54d549afee3f59011f  TrueCrypt 6.3 Source.tar.gz
    aa3a52a738e20496ba47fce841883c886718bc4a  TrueCrypt 6.3 Source.zip
    87f76143557d499639b2d858e3bb420a7157fbf1  TrueCrypt 6.3a Source.tar.gz
    d21d22754584e419cda332d4e9561145d79d3475  TrueCrypt 6.3a Source.zip
    a1e73ce533fb21f7c878d34fa9a62c55a605924e  TrueCrypt 7.0 Source.tar.gz
    ee70ab85801d38f1ca1047bfdd7038c9d135de93  TrueCrypt 7.0 Source.zip
    42be0f333e6791e7a122b3e1183e014cd3860198  TrueCrypt 7.0a Source.tar.gz
    8f9bf2ae13461fb3bfb4d1f7acb76c7c1c7ed29d  TrueCrypt 7.0a Source.zip
    b46c0fa5e1cbad25197b02d5232f5355b7abb1c9  TrueCrypt 7.1 Source.tar.gz
    0f053bf5a463c5c48cdcc9b0cb8c9ed3d5aa2fb2  TrueCrypt 7.1 Source.zip
    d43e0dbe05c04e316447d87413c4f74c68f5de24  TrueCrypt 7.1a Source.tar.gz
    4baa4660bf9369d6eeaeb63426768b74f77afdf2  TrueCrypt 7.1a Source.zip
    9050e23b327b645aae6cb77c2838a5676338fa6d  TrueCrypt-7.2-source-unix.tar.gz
    f562238ad3547a4ee9ba676306a7a742c35b63f3  TrueCrypt-7.2-source.zip