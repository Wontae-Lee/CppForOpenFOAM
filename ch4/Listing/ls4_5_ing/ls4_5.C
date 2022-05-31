/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2022 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    ls4_5

Description

\*---------------------------------------------------------------------------*/
#include "Enum.H"
#include "messageStream.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
class test
{
public:
    enum class selection
    {
        RELAXATION,
        IMPLICIT,
        EXPLICIT
    };
    const static Foam::NamedEnum<selection> selectionNames_;
};

const Foam::Enum<test::selection> test::selectionNames_(
    {
        {test::selection::RELAXATION, "relaxation"},
        {test::selection::IMPLICIT, "implicit"},
        {test::selection::EXPLICIT, "explicit"},
    });

int main(int argc, char *argv[])
{
    test obj;
    Foam::Info << obj.selectionName_s << Foam::endl;
    Foam::Info << obj.selectionName_s[test::selection::RELAXATION] << Foam::endl;

    if (obj.selectionName_s["relaxation"] == test::selection::RELAXATION)
    {
        Foam::Info << "selected relaxation method" << Foam::endl;
    }
    else
    {
        Foam::Info << "selected other method" << Foam::endl;
    }
    return 0;
}

// ************************************************************************* //
