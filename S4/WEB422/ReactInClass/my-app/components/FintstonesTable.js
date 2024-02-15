import { useState } from "react";

export default function FlintstonesTable(){
    const [users, setUsers] = useState([
        { user: 'fred', active: false, age: 40 },
        { user: 'pebbles', active: false, age: 1 },
        { user: 'barney', active: true, age: 36 },
      ]);

    return (<>
        <table>
            <thead>
                <tr>
                    <th>User Name</th>
                    <th>Active</th>
                    <th>Age</th>
                </tr>
            </thead>
            <tbody>
                {users.map((user, index)=>
                    <tr key={index}>
                        <td>{user.user}</td>
                        <td>{user.active ? <strong>Yes</strong> : <>No</>}{user.active && <> user is active</>}</td>
                        <td>{user.age}</td>
                    </tr>
                )}
            </tbody>
        </table>
    </>);
}