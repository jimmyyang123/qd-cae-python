
#include <string>

/* --------------------- NODE --------------------- */
const char* qd_node_class_docs = R"qddoc(

    Container for handling nodal data.

    Examples
    --------
        Get nodes by

        >>> femfile = D3plot(\"path/to/d3plot\")
        >>> node_list = femfile.get_nodes()
        >>> node = femfile.get_nodeByID(1)
        >>> node = femfile.get_nodeByIndex(1)
)qddoc";

const char* get_node_id_docs = R"qddoc(
    get_id()

    Get the id of the node.

    Returns
    -------
    id : int
        id of the node

    Examples
    --------
        >>> d3plot.get_nodeByID(1).get_id()
        1
)qddoc";

const char* get_node_coords_docs = R"qddoc(
    get_coords(iTimestep=0)

    Get the geometric nodal coordinates at a timestep. One needs to load the displacements
    before getting the coordinates at a different timestep.

    Parameters
    ----------
    iTimestep : int
        timestep at which to take the coordinates

    Returns
    -------
    coords : np.ndarray
        coordinate vector (x,z,y)

    Examples
    --------
        >>> d3plot = D3plot(\"path/to/d3plot\")
        >>> node.get_coords().shape
        (3L,)
        >>> # load disp
        >>> d3plot.read_states(\"disp\")
        >>> node.get_coords(iTimestep=10)
)qddoc";

const char* get_node_disp_docs = R"qddoc(
    get_disp()

    Get the time series of the displacement vector.

    Returns
    -------
    disp : np.ndarray
        time series of displacements

    Examples
    --------
        >>> node.get_disp().shape
        (34L, 3L)
)qddoc";

const char* get_node_vel_docs = R"qddoc(
    get_vel()

    Get the time series of the velocity vector.

    Returns
    -------
    disp : np.ndarray
        time series of displacements

    Examples
    --------
        >>> node.get_disp().shape
        (34L, 3L)
)qddoc";

const char* get_node_accel_docs = R"qddoc(
    get_accel()

    Get the time series of the acceleration vector.

    Returns
    -------
    disp : np.ndarray
        time series of acceleration

    Examples
    --------
        >>> node.get_accel().shape
        (34L, 3L)
)qddoc";

const char* get_node_elements_docs = R"qddoc(
    get_elements()

    Get the elements of the node.

    Returns
    -------
    elements : list(Element)
        elements of the node

    Examples
    --------
        >>> len( node.get_elements() )
        4
)qddoc";

/* --------------------- ELEMENT --------------------- */
const char* qd_element_class_docs = R"qddoc(

    Examples
    --------
        Get elements by

        >>> femfile = D3plot(\"path/to/d3plot\")
        >>> element_list = femfile.get_elements()
        >>> shells = femfile.get_elements(Element.shell)
        >>> id = 1
        >>> element = femfile.get_elementByID(Element.solid, id)
)qddoc";

const char* element_type_docs = R"qddoc(
    Element types:
     - Element.type.none (only used for filtering)
     - Element.type.beam
     - Element.type.shell
     - Element.type.solid
)qddoc";

const char* get_element_id_docs = R"qddoc(
    get_id()

    Get the id of the element.

    Returns
    -------
    id : int
        id of the element

    Examples
    --------
        >>> d3plot.get_elementByID(Element.shell, 1).get_id()
        1
)qddoc";

const char* get_element_plastic_strain_docs = R"qddoc(
    get_plastic_strain()

    Get the plastic strain of the element, if it was read with `d3plot.read_states`.

    Returns
    -------
    plastic_strain : np.ndarray
        time series of plastic strain

    Examples
    --------
        >>> element.get_plastic_strain().shape
        (34L,)
)qddoc";

const char* get_element_energy_docs = R"qddoc(
    get_energy()

    Get the energy of the element, if it was read with `d3plot.read_states`.

    Returns
    -------
    energy : np.ndarray
        time series of element energy

    Examples
    --------
        >>> element.get_energy().shape
        (34L,)
)qddoc";

const char* get_element_strain_docs = R"qddoc(
    get_strain()

    Get the strain tensor of the element, if it was read with `d3plot.read_states`.
    The strain vector contains the matrix components: [e_xx, e_yy, e_zz, e_xy, e_yz, e_xz]

    Returns
    -------
    strain : np.ndarray
        time series of the strain tensor data

    Examples
    --------
        >>> element.get_strain().shape
        (34L, 6L)
)qddoc";

const char* get_element_stress_docs = R"qddoc(
    get_strain()

    Get the stress tensor of the element, if it was read with `d3plot.read_states`.
    The stress vector contains the matrix components: [s_xx, s_yy, s_zz, s_xy, s_yz, s_xz]

    Returns
    -------
    stress : np.ndarray
        time series of the stress tensor data

    Examples
    --------
        >>> element.get_stress().shape
        (34L, 6L)
)qddoc";

const char* get_element_stress_mises_docs = R"qddoc(
    get_stress_mises()

    Get the mises stress of the element, if it was read with `d3plot.read_states`.

    Returns
    -------
    stress : np.ndarray
        time series of the mises stress

    Examples
    --------
        >>> element.get_stress_mises().shape
        (34L,)
)qddoc";

const char* get_element_nodes_docs = R"qddoc(
    get_nodes()

    Get the nodes of the element.

    Returns
    -------
    nodes : list(Node)
        nodes of the element

    Examples
    --------
        >>> elem_nodes = element.get_nodes()
)qddoc";

const char* get_element_coords_docs = R"qddoc(
    get_coords(iTimestep=0)

    Get the elements coordinates (mean of nodes).

    Parameters
    ----------
    iTimestep : int
        timestep at which to take the coordinates

    Returns
    -------
    coords : np.ndarray
        coordinate vector (x,z,y)

    Examples
    --------
        >>> element.get_coords().shape
        (3L,)
        >>> some_coords = element.get_coords(iTimestep=10) # disps must be loaded
)qddoc";

const char* get_element_history_docs = R"qddoc(
    get_history()

    Get the loaded history variables of the element.

    Returns
    -------
    history_vars : np.ndarray
        time series of the loaded history variables

    Examples
    --------
        >>> d3plot = D3plot(\"path/to/d3plot\",read_states=\"history 1 shell max\")
        >>> d3plot.get_elementByID(Element.shell, 1).get_history().shape
        (34L, 1L)

    Notes
    -----
        The history variable column index corresponds to the order in which
        the variables were loaded
)qddoc";

const char* get_element_estimated_size_docs = R"qddoc(
    get_estimated_size()

    Get the average element edge size of the element.

    Returns
    -------
    size : float
        average element edge size

    Examples
    --------
        >>> element.get_estimated_size()
        2.542
)qddoc";

const char* get_element_type_docs = R"qddoc(
    get_type()

    Get the type of the element.

    Returns
    -------
    element_type : str
        beam, shell or solid

    Examples
    --------
        >>> d3plot.get_elementByID(Element.beam, 1).get_type()
        type.beam
        >>> d3plot.get_elementByID(Element.shell, 1).get_type()
        type.shell
        >>> d3plot.get_elementByID(Element.solid, 1).get_type()
        type.solid
)qddoc";

const char* get_element_is_rigid_docs = R"qddoc(
    is_rigid()

    Get the status, whether the element is a rigid (flag for shells only).
    Rigid shells have no state data!

    Returns
    -------
    is_rigid : bool
        rigid status of the element

    Examples
    --------
        >>> d3plot = D3plot(\"path/to/d3plot\", read_states=\"stress_mises max\")
        >>> elem1 = d3plot.get_elementByID(Element.shell, 451)
        >>> elem1.is_rigid()
        False
        >>> elem1.get_stress_mises().shape
        (34L,)
        >>> elem2 = d3plot.get_elementByID(Element.shell, 9654)
        >>> elem2.is_rigid()
        True
        >>> elem2.get_stress_mises().shape # rigid shells lack state data
        (0L,)
)qddoc";

/* ----------------------- PART ---------------------- */
const char* get_part_id_docs = R"qddoc(
    get_id()

    Get the id of the part.

    Returns
    -------
    id : int
        id of the part

    Examples
    --------
        >>> d3plot = D3plot(\"path/to/d3plot\")
        >>> part = d3plot.get_partByID(1)
        >>> part.get_id()
        1
)qddoc";

const char* get_part_name_docs = R"qddoc(
    get_name()

    Get the name of the part. It's the same name as in the input deck.

    Return
    -------
    name : str
        name of the part

    Examples
    --------
        >>> d3plot = D3plot(\"path/to/d3plot\")
        >>> part = d3plot.get_partByID(1)
        >>> part.get_name()
        'PLATE_C'
)qddoc";

const char* get_part_nodes_docs = R"qddoc()
    get_nodes()

    Get the nodes of the part. Note that a node may belong to two parts,
    since only the elements are uniquely assignable.

    Returns
    -------
    nodes : list(Node)
        nodes belonging to the elements of the part

    Examples
    --------
        >>> d3plot = D3plot(\"path/to/d3plot\")
        >>> part = d3plot.get_partByID(1)
        >>> len( part.get_nodes() )
        52341
)qddoc";

const char* get_part_elements_docs = R"qddoc(
    get_elements(element_filter=Element.none)

    Get the elements of the part.

    Parameters
    ----------
    element_filter : str
        Optional element type filter. May be beam, shell or solid.

    Returns
    -------
    elements : list(Element)
        list of Elements

    Examples
    --------
        >>> d3plot = D3plot(\"path/to/d3plot\")
        >>> part = d3plot.get_partByID(1)
        >>> len( part.get_elements() )
        49123
        >>> len( part.get_elements(Element.shell) )
        45123
)qddoc";

/* ----------------------- DB_NODES ---------------------- */
const char* dbnodes_description = R"qddoc(

    This class is managing the nodes internally in the
    background of a FEMFile. It can never be constructed
    or attained individually.

    Examples
    --------
        >>> # DB_Nodes is inherited by FEMFile
        >>> issubclass(FEMFile, DB_Nodes)
        True
        >>> # Use DB_Nodes functions
        >>> femfile = KeyFile(\"path/to/keyfile\")
        >>> femfile.get_nNodes()
        45236

)qddoc";

const char* dbnodes_get_nodeByID_docs = R"qddoc(
    get_nodeByID(id)

    Parameters
    ----------
    id : int or list(int)
        node id or list of node ids

    Returns
    -------
    node : Node or list(Node)
        requested Node(s)

    Raises:
    -------
    ValueError
        if `id` does not exist.

    Examples
    --------
        >>> # get by single id
        >>> node = femfile.get_nodeByID(1)
        >>> # get a list of nodes at once
        >>> list_of_nodes = femfile.get_nodeByID( [1,2,3] )
)qddoc";

const char* dbnodes_get_nodeByIndex_docs = R"qddoc(
    get_nodeByIndex(index)

    Parameters
    ----------
    index : int or list(int)
        internal node index or list inf indexes

    Returns
    -------
    node : Node or list(Node)
        Node(s)

    Notes
    -----
        The internal index starts at 0 and ends at
        `femfile.get_nNodes()`.

    Raises:
    -------
    ValueError
        if `index` larger `femfile.get_nNodes()`.

    Examples
    --------
        >>> # single index
        >>> node = femfile.get_nodeByIndex(1)
        >>> # get a list of nodes at once
        >>> list_of_nodes = femfile.get_nodeByIndex( [1,2,3] )
)qddoc";

const char* get_nodes_docs = R"qddoc(
    get_nodes()

    Returns
    -------
    nodes : list(Node)
        list of node objects

    Examples
    --------
        >>> list_of_nodes = femfile.get_nodes()
    )qddoc";

const char* dbnodes_get_nNodes_docs = R"qddoc(
    get_nNodes()

    Returns
    -------
    nNodes : int
        number of nodes in the file

    Examples
    --------
        >>> femfile.get_nNodes()
        43145
)qddoc";

/* ----------------------- DB_ELEMENTS ---------------------- */
const char* get_filepath_docs = R"qddoc(
get_filepath()

Returns
-------
filepath : str
    Filepath of the femfile.

Examples
--------
    >>> femfile.get_filepath()
    \"path/to/femfile\"
)qddoc";

const char* get_elements_docs = R"qddoc(
get_elements(element_filter=Element.none)

Parameters
----------
element_filter : Element.type
    Optional element type filter. May be beam, shell or solid.

Returns
-------
elements : list(Element)
    list of Elements

Raises:
-------
ValueError
    if invalid `element_filter` is given.

Notes
-----
Get the elements of the femfile. One may use a filter by type.

Examples
--------
    >>> all_elements = femfile.get_elements()
    >>> shell_elements = femfile.get_elements(Element.shell)
)qddoc";

const char* get_nElements_docs = R"qddoc(
get_nElements(element_filter=Element.none)

Parameters
----------
element_filter : Element.type
    Optional element type filter. May be beam, shell or solid.

Returns
-------
nElements : int
    number of elements

Examples
--------
    >>> femfile.get_nElements()
    43156
)qddoc";

const char* get_elementByID_docs = R"qddoc(
get_elementByID(element_filter, id)

Parameters
----------
element_filter : Element.type
    type of the element. Must be beam, shell or solid.
id : int or list(int)
    element id or list of ids

Returns
-------
element : Element
    Element(s) depending on the arguments

Notes
-----
    Since ids in the dyna file are non unique for
    different element types, one has to specify the
    type too.

Raises:
-------
ValueError
    if `element_filter` is invalid or `id` does not exist.

Examples
--------
    >>> # single element
    >>> elem = femfile.get_elementByID(Element.shell, 1)
    >>> # multiple elements
    >>> list_of_shells = femfile.get_elementByID(Element.shell, [1,2,3])
    >>> # whoever had the great id of non unique ids ...
    >>> femfile.get_elementByID(Element.beam, 1).get_type()
    type.beam
    >>> femfile.get_elementByID(Element.solid, 1).get_type()
    type.solid
)qddoc";

/* ----------------------- DB_PARTS ---------------------- */

/* ----------------------- FEMFILE ---------------------- */

/* ----------------------- D3PLOT ---------------------- */

/* ----------------------- KEYFILE ---------------------- */